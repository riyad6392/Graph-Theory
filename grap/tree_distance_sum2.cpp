//https://cses.fi/problemset/task/1133
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
ll n;
const int N=2e5;
vector<ll>vt[N+10];
ll sub_tr_sz[N+10];
ll sub_tr_ans[N+10];
ll ans[N+10];

void dfs(ll node,ll par)
{
    ll cnt=1;
    ll dis=0;


    for(auto a : vt[node])
    {
        if(a==par)continue;

        dfs(a,node);
        cnt+=sub_tr_sz[a];
        dis+=sub_tr_sz[a]+sub_tr_ans[a];

    }

    sub_tr_sz[node]=cnt; // sub tree ar total node count kortese
    sub_tr_ans[node]=dis;  // distance ar sum calculate

}

void solve(ll node,ll par,ll par_ans)
{
    ans[node]=sub_tr_ans[node]+(par_ans+(n-sub_tr_sz[node]));  // firsta node ar ans calculate kortasi

    for(auto a : vt[node])
    {
        if(a==par) continue;
        solve(a,node,ans[node]-(sub_tr_ans[a]+sub_tr_sz[a]));  // 2 ta sub tree bag kore desi, main tree thake bag korar shomoi parent ar part ar ans solve functiona detasi
    }

}


int main()
{

    fast_io;
    int t;

        cin>>n;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            vt[u].push_back(v);
            vt[v].push_back(u);
        }

        dfs(1,-1);
        solve(1,0,0);

        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;




}
