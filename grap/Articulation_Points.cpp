#include<bits/stdc++.h>
using namespace std;
int vis[1000],intm[1000],lowtm[1000];
int timer;
set<int>ans;
vector<int>vt[1000];

void dfs(int node,int par)
{
    vis[node]=1;
    intm[node]=timer;
    lowtm[node]=timer;
    timer++;
    int cnt=0;
    for(auto child: vt[node])
    {
        if(child==par) continue;
        if(vis[child]==1)
        {
            lowtm[node]=min(lowtm[node],intm[child]);
        }
        else
        {
            dfs(child,node);
            cnt++;
            lowtm[node]=min(lowtm[node],lowtm[child]);
            if(lowtm[child]>=intm[node] && par!=-1) //root node articulation point hobe nah
            {

                ans.insert(node);
            }

        }


    }
    // root node with more than one child
    if(par==-1 && cnt>1) //root node articulation point hobe joji root ar sub graph 1 ar basi thake

    {
        ans.insert(node);
    }

}

int main()
{
  while(1)
  {
  int n,m;
  cin>>n>>m;
  if(n==0 && m==0)break;
  for(int i=1;i<=n;i++)
  {
      vt[i].clear();
      vis[i]=0;
  }
  for(int i=0;i<m;i++)
  {
      int u,v;
      cin>>u>>v;
      vt[u].push_back(v);
      vt[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
      if(vis[i]==0)
      {
          dfs(i,-1);
      }
  }
  cout<<ans.size()<<endl;
  for(auto a:ans)
  {
      cout<<a<<" ";
  }
  cout<<endl;

  }


}
