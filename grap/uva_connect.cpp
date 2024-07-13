#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>vt[N+2];
bool vis[N+2];
int total;
void dfs(int nod)
{
    total++;
    vis[nod]=1;
    for(int i=0; i<vt[nod].size(); i++)
    {
        int kl=vt[nod][i];
        if(vis[kl]==0)
        {
            dfs(kl);
        }
    }


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n,l;
        cin>>n>>m>>l;
        for(int i=1; i<=N; i++)
        {
            vis[i]=0;
        }
        total=0;
        for(int i=1; i<=m; i++)
        {
            int a,b;
            cin>>a>>b;
            vt[a].push_back(b);
        }
        for(int i=1; i<=l; i++)
        {
            int aa;
            cin>>aa;
            if(vis[aa]==0)
                dfs(aa);
        }
        cout<<total<<endl;
        for(int i=0; i<n; i++)
        {
            vt[i].clear();
        }

    }
}

