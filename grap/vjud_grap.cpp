#include<bits/stdc++.h>
#define ll long long int
const int N=1e5;
using namespace std;
vector<vector<pair<int,int>>>vt;
vector<ll>cost;
vector<ll>vlu;
map<int,int>mp;
vector<ll>tt;
ll dj,T;
void  dijstra()
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
     for(int i=1;i<=T;i++)
  {
     pq.push({vlu[tt[i]],tt[i]});
      //cost[aa]=0;
  }
    //pq.push({vlu[dj],dj});
    //cout<<cost[dj]<<" "<<dj<<endl;
    while(!pq.empty())
    {
        ll f=pq.top().first;
        ll s=pq.top().second;
        pq.pop();
        for(int i=0;i<vt[s].size();i++)
        {
          ll node=vt[s][i].first;
          ll dist=vt[s][i].second;
          ll ans=cost[node]+dist+vlu[s];
          cout<<s<<" "<<node<<" node "<<ans<<" "<<vlu[node]<<" fl ";
          if(ans<vlu[node])
          {
              vlu[node]=ans;
              cout<<ans;
              //cost[node]=ans;
              pq.push({vlu[node],node});

          }
          cout<<endl;
        }

    }

}

int main()
{
  int n,m;
  ll mm=999999999999;
  cin>>n>>m>>T;
  vt.resize(n+2);
  cost.resize(n+2);
  vlu.resize(n+2);
  tt.resize(n+2);
  for(int i=1;i<=m;i++)
  {
      int a,b,c;
      cin>>a>>b>>c;
      vt[a].push_back(make_pair(b,c));
      vt[b].push_back(make_pair(a,c));
  }
  for(int i=1;i<=n;i++)
  {
      cin>>cost[i];
  }
  for(int i=1;i<=n;i++)
  {
      vlu[i]=mm;
  }
    ll aa;
    ll mn=99999999;
  for(int i=1;i<=T;i++)
  {

      cin>>tt[i];
      vlu[tt[i]]=cost[tt[i]];
      //cost[aa]=0;
  }
  dijstra();
  for(int i=1;i<=n;i++)
  {
      cout<<vlu[i]<<endl;
  }


}


