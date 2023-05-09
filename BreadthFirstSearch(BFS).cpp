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

void initializeVisited(int v,int *visited){
    for(int i=0;i<v;i++){
        visited[i]=0;
    }
}

void BFS(int v,node **adj_list,int src,int visited[]){
    node *temp;
    int queue[v],front=0,rear=0;
    queue[++rear]=src;
    while(front<=rear){
        int current=queue[front++];
        temp=adj_list[current];
        visited[current]=1;
        cout<<current<<"  ";
        while(temp!=NULL){
            if(visited[temp->info]!=1){
                queue[++rear]=temp->info;
                visited[temp->info]=1;
            }
            temp=temp->next;
        }
    }
}
int main(){
    int v,ch,src;
    cout<<"Enter number of vertices: ";
    cin>>v;
    int visited[v];
    node *adj_list[v];

    for(int i=0;i<v;i++){
        adj_list[i]=NULL;
    }

    readGraph(v,adj_list);
    do{
        cout<<"Enter 1 for BFS, 2 for printing the graph, 3 for exit: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter source node: ";
                    cin>>src;
                    initializeVisited(v,visited);
                    BFS(v,adj_list,src,visited);
                    break;
            case 2: printGraph(v,adj_list);
                    break;
            case 3: exit(0);
            default: cout<<"Invalid argument!!"<<endl;
        }
    }while(ch);
    return 0;
}