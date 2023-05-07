#include<iostream>
using namespace std;

typedef struct node
{
    int info;
    struct node *next;
}node;

void readGraph(int v,node **adj_list)
{
    node *new_node,*last_node=NULL;
    int info;
    int k;
    for(int i=0;i<v;i++)
    {
        cout<<"Enter number of nodes adjacent to "<<i<<" vertice : ";
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            new_node=(node *)malloc(sizeof(node));
            cout<<"Enter the "<<j<<" neighbour of "<<i<<" : ";
            cin>>info;
            new_node->info=info;
            new_node->next=NULL;
            if(adj_list[i]==NULL)
            {
                adj_list[i]=new_node;
            }
            else
            {
                last_node->next=new_node;
            }
            last_node=new_node;
        }
    }
}

void printGraph(int v,node **adj_list)
{
    for(int i=0;i<v;i++){
        node *temp=adj_list[i];
        if(temp!=NULL){
            cout<<"Vertices adjacent to vertice "<<i<<" are: ";
        }
        else{
            cout<<"Vertice "<<i<<" has no adjacency list.";
        }
        while(temp!=NULL){
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main(){
    int v;
    cout<<"Enter number of vertices: ";
    cin>>v;

    node *adj_list[v];

    for(int i=0;i<v;i++){
        adj_list[i]=NULL;
    }

    readGraph(v,adj_list);
    printGraph(v,adj_list);
    return 0;
}