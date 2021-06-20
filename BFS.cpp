#include<bits/stdc++.h>
using namespace std;
int color[30],adj[30][30],parent[30],dis[30];
void BFS(int n,int s)
{
      queue<int>q;
      int u;
      for(int i=1;i<=n;i++)
      {
          color[i]=2;
          dis[i]=INT_MAX;
      }
      q.push(s);dis[s]=0;color[s]=3;
      while(!q.empty())
      {
          u=q.front();
          q.pop();
          for(int v=1;v<=n;v++)
          {
              if(adj[u][v]==1)
              {
                  if(color[v]==2)
                  {
                      color[v]=3;
                      dis[v]=dis[u]+1;
                       parent[v]=u;
                       q.push(v);                  }
              }
          }
          color[u]=4;
      }

}
int main()
{
    freopen("input.txt" , "r" , stdin);
    ofstream out("output.txt" );
    int n,a,b,x;
    cin>>n>>x;

    while(cin>>a>>b){
        if(x){
             adj[a][b]=1;
             adj[b][a]=1;
        }
        else{
            adj[a][b]=1;
        }
    }
  BFS(n,1);

    return 0;
}
