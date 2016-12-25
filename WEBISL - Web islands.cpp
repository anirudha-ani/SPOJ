#include <bits/stdc++.h>

using namespace std;

/**
Node number starts from 1
**/
/**
Source - http://www.spoj.com/problems/WEBISL/
Method - Basic Strongly Connected component
**/
#define MAX_NODE 100005

int edges , vertices , u , v , no_of_SCC_found , extra_Edge_needed;


vector <int> adjacency_list[MAX_NODE];
vector <int> adjacency_list_reversed[MAX_NODE];
vector <int> SCC_adjacency_list[MAX_NODE];
vector <int> SCC_adjacency_list_reversed[MAX_NODE];

int visited[MAX_NODE];
int reverse_visited[MAX_NODE];
int SCC_ID[MAX_NODE];


stack <int> finish_time;
vector <int> SCC[MAX_NODE];

void DFS(int current_node)
{
    int no_of_connected_node = adjacency_list[current_node].size();

    visited[current_node] = 1 ;

    for(int i = 0 ; i < no_of_connected_node ; i++)
    {
        if(visited[adjacency_list[current_node][i]] == 0)
        {
            visited[adjacency_list[current_node][i]] = 1;
            DFS(adjacency_list[current_node][i]);
        }
    }

    finish_time.push(current_node);
}

void reverseDFS(int current_node)
{
    int no_of_connected_node = adjacency_list_reversed[current_node].size();

    reverse_visited[current_node] = 1 ;

    for(int i = 0 ; i < no_of_connected_node ; i++)
    {
        if(reverse_visited[adjacency_list_reversed[current_node][i]] == 0)
        {
            reverse_visited[adjacency_list_reversed[current_node][i]] = 1;
            reverseDFS(adjacency_list_reversed[current_node][i]);
        }
    }
    SCC[no_of_SCC_found].push_back(current_node);
    SCC_ID[current_node] = no_of_SCC_found;
}

int findSCC()
{

    for(int i = 1 ; i <= vertices ; i++)
    {
        if(visited[i] == 0)
        {
            DFS(i);
        }
    }

    while(finish_time.empty() != true)
    {
        int current_node = finish_time.top();
        //cout << "::" << current_node << endl ;
        finish_time.pop();

        if(reverse_visited[current_node] == 0)
        {
            no_of_SCC_found++;

            reverseDFS(current_node);
        }
    }
}

int main()
{
    /** Initialization start **/
    for(int i = 0 ; i < MAX_NODE ; i++)
    {
        adjacency_list[i].clear();
        adjacency_list_reversed[i].clear();
        SCC[i].clear();
        SCC_adjacency_list[i].clear();
        SCC_adjacency_list_reversed[i].clear();
    }


    while(finish_time.empty()!=true)
    {
        finish_time.pop();
    }

    memset(visited, 0 , sizeof(visited));
    memset(reverse_visited , 0 , sizeof(reverse_visited));
    memset(SCC_ID , 0 , sizeof(SCC_ID));

    no_of_SCC_found = 0 ;
    extra_Edge_needed = 0 ;

    map<pair<int , int> , int> edge_exists;

    /**Initialization finish **/


    scanf("%d %d", &vertices , &edges);

    for(int i = 0 ; i < edges ; i++)
    {
        scanf("%d %d", &u , &v);
        u++;
        v++;
        adjacency_list[u].push_back(v);
        adjacency_list_reversed[v].push_back(u);
    }

    findSCC();

    for(int i = 1 ; i <= no_of_SCC_found ; i++)
    {
        sort(SCC[i].begin() , SCC[i].end());
    }

    for(int i = 1 ; i <= vertices ; i++)
    {
        int id = SCC_ID[i];
        int ans  = SCC[id][0] - 1;
        printf("%d\n",ans);
    }
//    printf("%d\n", no_of_SCC_found);
//
//
//    printf("%d\n",extra_Edge_needed);
    return 0;
}

