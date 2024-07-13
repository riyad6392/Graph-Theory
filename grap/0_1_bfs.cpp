#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e5+10;
const int inf=1e9+10;
vector<pair<int,int>>vt[N];
vector<int>lev(N,inf);
int n,m;

int bfs()
{
     deque<int>dq;
     dq.push_back(1);
     lev[1]=0;

     while(!dq.empty())
     {
         int cur_v=dq.front();
         dq.pop_front();

         for(auto a : vt[cur_v])
         {
           int node=a.first;
           int wt=a.second;
         if(lev[cur_v]+wt<lev[node])
         {
             lev[node]=lev[cur_v]+wt;
             if(wt==1)
             {
                 dq.push_back(node);
             }
             else
             {
                 dq.push_front(node);
             }
         }

         }

     }
     return lev[n];

}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        vt[u].push_back({v,0});
        vt[v].push_back({u,1});
    }

    int ans=bfs();
    if(ans==inf)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }

}
