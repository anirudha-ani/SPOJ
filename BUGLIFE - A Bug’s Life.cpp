#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int bug_sexuality[2005];
int graph[2005][2005];

bool isBipartiate(int bugs , int initiate)
{

    bug_sexuality[initiate] = 1;

    queue <int> q;

    q.push(initiate);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v = 0 ; v < bugs ; v++)
        {
            if((graph[u][v] == 1) &&( bug_sexuality[v] == -1))
            {
                bug_sexuality[v] = 1 - bug_sexuality[u];
                q.push(v);
            }
            else if((graph[u][v] == 1) && (bug_sexuality[u] == bug_sexuality[v]))
            {
                return false;
            }

        }
    }
    return true;
}

int main()
{
    int scenerio , bugs , interections , bug1 , bug2;

    scanf("%d", &scenerio);

    for(int i = 1 ; i <= scenerio ; i++)
    {
        scanf("%d %d", &bugs , &interections);
        memset(graph , 0 , sizeof(graph));

        for(int j = 1 ; j <= interections ; j++)
        {
            scanf("%d %d",&bug1 , &bug2 );
            if(bug1 == bug2) continue;
            graph[bug1-1][bug2-1] = 1;
            graph[bug2-1][bug1-1] = 1;
        }
        bool conflict = false;
        memset(bug_sexuality , -1 , sizeof(bug_sexuality));
        for(int i = 0 ; i < bugs ;i++)
        {
            if(bug_sexuality[i] == -1)
            {
                if(!isBipartiate(bugs , i))
                {
                    conflict = true;
                    break;
                }
            }
        }
        if(conflict)
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n",i);
        }
        else
        {
             printf("Scenario #%d:\nNo suspicious bugs found!\n",i);
        }

    }
    return 0;
}
