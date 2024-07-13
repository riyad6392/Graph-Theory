#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll vis[1003][1003];
ll br[1003][1003];
ll kl=0;
void dfs(int i,int j)
{
    vis[i][j]=1;
    //cout<<br[i][j];
    if(br[i-1][j]!=0 && vis[i-1][j]==0)
    {
        kl+=br[i-1][j];
        dfs(i-1,j);

    }
     if(br[i][j-1]!=0 && vis[i][j-1]==0)
    {
        kl+=br[i][j-1];
        dfs(i,j-1);

    }
     if(br[i][j+1]!=0 && vis[i][j+1]==0)
    {
        kl+=br[i][j+1];
        dfs(i,j+1);

    }
     if(br[i+1][j]!=0 && vis[i+1][j]==0)
    {
        kl+=br[i+1][j];
        dfs(i+1,j);

    }
   // cout<<kl<<endl;



}

int main()
{
    ll  t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll ar[n+3][m+3];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ar[i][j];
            }
        }
       // ll br[n+3][m+3];
         for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                br[i][j]=0;
            }
        }
         for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                br[i][j]=ar[i][j];
            }
        }
        ll mx=0;
          for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                vis[i][j]=0;
            }
        }

         for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
               if(vis[i][j]==0 && br[i][j]!=0)
               {
                   kl=br[i][j];
                   dfs(i,j);
                   mx=max(mx,kl);
               }
            }
        }
        cout<<mx<<endl;







    }

}
