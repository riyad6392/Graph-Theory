#include<bits/stdc++.h>
using namespace std;
const int inf=1e17;
vector<vector<pair<int,int>>>vt;
vector<int>dis;
int k,n,m;
void dijkstra()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,k});
    while(!pq.empty())
    {
        int aa=pq.top().first;
        int bb=pq.top().second;
        pq.pop();
        for(int i=0;i<vt[bb].size();i++)
        {
            int ndd=vt[bb][i].first;
            int cost=vt[bb][i].second;
            int mm=max(dis[bb],cost);
            if(cost<dis[ndd] && dis[ndd]!=mm)
            {
                dis[ndd]=max(dis[bb],cost);
                 cout<<dis[ndd]<<" "<<ndd<<endl;
                pq.push({dis[ndd],ndd});
            }

        }

    }


}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m;
        vt.clear();
        dis.clear();
        int pp=max(n,m);
        vt.resize(pp+2);
        dis.resize(pp+2);
           for(int j=0;j<n;j++)
        {
            dis[j]=inf;
        }
        for(int j=0;j<m;j++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            vt[a].push_back(make_pair(b,w));
            vt[b].push_back(make_pair(a,w));
        }
        cin>>k;
        dis[k]=0;
        dijkstra();
        cout<<"Case "<<i<<":"<<endl;
        for(int j=0;j<n;j++)
        {
            if(dis[j]==inf)
            {
                cout<<"Impossible"<<endl;
            }
            else
            {
                cout<<dis[j]<<endl;
            }
        }

    }

}
