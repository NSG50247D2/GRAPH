#include <iostream>
using namespace std;

void printGraph(int v,int **adj_mat){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int v;
    cout<<"Enter total number of vertices: ";
    cin>>v;
    int **adj_mat=new int*[v];
    for(int i=0; i<v; i++){
        adj_mat[i]=new int[v];
        for(int j=0; j<v; j++){
            adj_mat[i][j]=0;
        }
    }
    int src=0,dst=0;
    while((src!=-1 && dst!=-1) && (src<v && dst<v)){
        cout<<"Enter source node from 0 to "<<v-1<<"and destination node from 0 to "<<v-1<<": ";
        cin>>src;
        cin>>dst;
        if((src!=-1 && dst!=-1) && (src<v && dst<v)) {
            adj_mat[src][dst] = 1;
            adj_mat[dst][src] = 1;
        }
    }
    printGraph(v,adj_mat);
    return 0;
}
