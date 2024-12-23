/* 9)9a) Write a program to traverse a graph using BFS method.
9b) Write a program to traverse a graph using DFS method. */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void BFS(int adj[15][15],int V,int i_vertex){
    int q[5],front=0,rear=0;
    bool visited[5]={false};
    visited[i_vertex]=true;
    q[rear++]=i_vertex;
    while(front<rear){
        int curr=q[front++];
        printf("%d ",curr);
        for(int i=0;i<V;i++){
            if(adj[curr][i]==1 && !visited[i]){
                visited[i]=true;
                q[rear++]=i;
            }
        }
    }
}

void addEdge(int adj[15][15],int row,int column){
    adj[row][column]=adj[column][row]=1;
}

void DFS(int adj[15][15],int V,int i_vertex,bool visited[V]){
    visited[i_vertex]=true;
    printf("%d ",i_vertex);
    for(int i=0;i<V;i++){
        if(adj[i_vertex][i]==1 && !visited[i]){
            DFS(adj,V,i,visited);
        }
    }
}

int main(){
    int V=5;
    int adj[15][15]={0};
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,4);
    addEdge(adj,3,4);
    printf("DFS Traversal with initial node 0:");
    bool visited[5]={false};
    DFS(adj,V,0,visited);
    printf("\nBFS Traversal with initial node 0:");
    BFS(adj,V,0);
    return 0;
}

