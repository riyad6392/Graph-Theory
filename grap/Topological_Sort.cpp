#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
vector<int>ans;
vector<int>vt[200002];

void bfs(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.push_back(cur);
        for(auto child:vt[cur])
        {
            mp[child]--;
            if(mp[child]==0)q.push(child);
        }

    }
    if(ans.size()!=n)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
    for(auto a:ans)
    {
        cout<<a<<" ";
    }
    cout<<endl;
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
        mp[v]++;

    }
    bfs(n);


}

