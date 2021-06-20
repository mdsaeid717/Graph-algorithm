#include<bits/stdc++.h>

using namespace std;

vector<int>graph[10];
int dis[10];
bool visi[10];

void bfs(int source)
{
    queue<int>q;
    dis[source]=0;
    visi[source]=1;
    q.push(source);

    if(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=0;i<graph[node].size();i++)
        {
            int next=graph[node][i];
            if(visi[next]==0)
            {
                visi[next]=1;
                dis[next]=dis[next]+1;
                q.push(next);
            }
        }
    }

}

int main()
{
    int vertex,edge;

    cin>>vertex>>edge;

    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int source;

    cin>>source;
    bfs(source);

    return 0;
}
