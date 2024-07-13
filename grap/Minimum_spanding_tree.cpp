#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int Size[N];
void make(int n)
{
    parent[n]=n;
    Size[n]=1;

}
int Find(int rt)
{
if(rt==parent[rt]) return rt;
else return parent[rt]=Find(parent[rt]);

}
void Union(int a,int b)
{
  a=Find(a);
  b=Find(b);
  if(a==b)
  {

  }
  else
  {
      if(Size[a]<Size[b]) swap(a,b);
      parent[b]=a;
      Size[a]+=Size[b];

  }

}

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
      make(i);
  }
  vector<pair<int,pair<int,int>>>vt;
  for(int i=0;i<m;i++)
  {
      int u,v,w;
      cin>>u>>v>>w;
      vt.push_back({w,{u,v}});

  }
  sort(vt.begin(),vt.end());
  //cout<<vt[0].first<<endl;
  int total_cost=0;
  for(auto a : vt)
  {
      int wt=a.first;
      int uu=a.second.first;
      int vv=a.second.second;
     // cout<<wt<<" "<<uu<<" "<<vv<<endl;
      if(Find(uu)==Find(vv)) continue;
      Union(uu,vv);
      total_cost+=wt;
      cout<<uu<<" "<<vv<<endl;
  }
  cout<<total_cost<<endl;

}
