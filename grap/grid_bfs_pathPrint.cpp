//https://cses.fi/problemset/task/1193
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1}; // horizontal and vertical (x,y)
bool vis[1002][1002];
char c,par[1002][1002],ans[1002];
queue<pair<int,int>>q;
int n,m,sx,sy,ex,ey;


int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>c;
            if(c=='#')
            {
                vis[i][j]=1;
            }
            else if(c=='A')
            {
                sx=i;
                sy=j;
            }
            else if(c=='B')
            {
                ex=i;
                ey=j;
            }
        }

    }

    q.push({sx,sy});
    vis[sx][sy]=1;
    while(!q.empty())
    {
        pair<int,int>pp=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int dx=pp.first+h[i];
            int dy=pp.second+v[i];

             if(0 <= dx && dx < n && 0 <= dy && dy < m && !vis[dx][dy])
             {
                      if(i==0) par[dx][dy]='D';
                 else if(i==1) par[dx][dy]='U';
                 else if(i==2) par[dx][dy]='R';
                 else if(i==3) par[dx][dy]='L';

                 q.push({dx,dy});
                 vis[dx][dy]=1;
             }

        }

    }
    if(vis[ex][ey]==0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        vector<char>res;

       pair<int,int>ck={ex,ey};;
       while(ck.first!=sx || ck.second!=sy)
       {
           res.push_back(par[ck.first][ck.second]);

           if(par[ck.first][ck.second]=='D') ck={ck.first-1,ck.second};    //olta deka jabo, R hole  L a jabo
           else if(par[ck.first][ck.second]=='U') ck={ck.first+1,ck.second};
           else if(par[ck.first][ck.second]=='R') ck={ck.first,ck.second-1};
           else if(par[ck.first][ck.second]=='L') ck={ck.first,ck.second+1};

       }

       cout<<res.size()<<endl;
       reverse(res.begin(),res.end());
       for(auto a : res)
       {
           cout<<a;
       }
       cout<<endl;




    }



}

