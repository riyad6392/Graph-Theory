//https://lightoj.com/problem/commandos
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e6;
vector<ll>vt[N+5];
vector<bool>vis;
vector<ll>dis_s,dis_e;

void bfs(ll node, vector<ll>& dis)
{
    vis[node]=true;
    queue<ll>pq;
    pq.push(node);
    while(!pq.empty())
    {
        ll tp=pq.front();
        pq.pop();
        for(auto a : vt[tp])
        {
            if(vis[a]==false)
            {
                vis[a]=true;
                pq.push(a);
                dis[a]=dis[tp]+1;
            }

        }

    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
   for(int c=1;c<=t;c++)
    {
        ll n,r,s,e;
        cin>>n>>r;

        for(int i=0;i<n;i++)
        {
            vt[i].clear();
        }
        for(int i=0;i<r;i++)
        {
            ll u,v;
            cin>>u>>v;
            vt[u].push_back(v);
            vt[v].push_back(u);
        }
        cin>>s>>e;

        vis.assign(n,false);
        dis_s.assign(n,0LL);
        dis_e.assign(n,0LL);

        bfs(s,dis_s);
        vis.assign(n,false);
        bfs(e,dis_e);

        ll ans=0;

        for(int i=0;i<n;i++)
        {
            ans=max(ans,dis_s[i]+dis_e[i]);
        }

       cout<<"Case "<<c<<": "<<ans<<endl;



    }

}
