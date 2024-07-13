#include<bits/stdc++.h>
using namespace std;
int vis[1000],intm[1000],lowtm[1000];
int timer;
vector<int>vt[1000];

void dfs(int node ,int par)
{
    vis[node]=1;
    //cout<<node<<endl;
    intm[node]=timer;
    lowtm[node]=timer;
    timer++;
    for(auto child : vt[node])
    {
        if(child==par) continue;
        if(vis[child]==1)
        {
            lowtm[node]=min(lowtm[node],intm[child]);

        }
        else
        {
            dfs(child,node);
            if(lowtm[child]>intm[node])
            {
                cout<<node<<"-->"<<child<<endl;
            }
            lowtm[node]=min(lowtm[node],lowtm[child]);

        }
    }

}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    dfs(1,-1);


}

