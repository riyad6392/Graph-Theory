#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int>vt[200005];
int depth[200005];

void dfs(int node,int par)
{
    for(auto a : vt[node])
    {
        if(a==par)
            continue;
        depth[a]=depth[node]+1;
        dfs(a,node);
    }

}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    dfs(1,-1);

    int max_dap=-1;
    int dap_nd;
    for(int i=1; i<=n; i++)
    {
        if(max_dap<depth[i])
        {
            max_dap=depth[i];
            dap_nd=i;
        }

    }

    for(int i=1; i<=n; i++)
    {
        depth[i]=0;

    }
    dfs(dap_nd,-1);

    max_dap=-1;
    for(int i=1; i<=n; i++)
    {
        if(max_dap<depth[i])
        {
            max_dap=depth[i];
        }

    }

    cout<<max_dap<<endl;





}
