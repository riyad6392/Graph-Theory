#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<vector<pair<int,int>> >vt;
vector<int>dis;
const int inf=1e17;

void dijkstra()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        int d=pq.top().first;
        int nod=pq.top().second;
        pq.pop();
        for(int i=0;i<vt[nod].size();i++)
        {
            int ndd=vt[nod][i].first;
            int cost=vt[nod][i].second;
            if((d+cost)<dis[ndd])
            {
                dis[ndd]=d+cost;
                pq.push({dis[ndd],ndd});
            }


        }

    }


}

int main()
{
    int n,m;
    cin>>n>>m;
    vt.resize(n+2);
    dis.resize(n+2);
    for(int i=1;i<=n;i++)
    {
        dis[i]=inf;
    }
    dis[1]=0;
   for(int i=1;i<=m;i++)
   {
       int a,b,w;
       cin>>a>>b>>w;
       vt[a].push_back(make_pair(b,w));
       vt[b].push_back(make_pair(a,w));

   }
   dijkstra();
   for(int i=1;i<=n;i++)
   {
       cout<<dis[i]<<endl;
   }


}
