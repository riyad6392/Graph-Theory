#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1e9+7;
int main()
{
    ll n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    dp[0][0]=1;
   // s[0][0]='.';
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            if(s[i][j]!='*')
            {
                if(i-1>=0)
                {
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]=dp[i][j]%mod;
                }
                if(j-1>=0)
                {
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]=dp[i][j]%mod;
                }

            }
        }
    }

    if(s[0][0]=='*')
    {
        cout<<0<<endl;
    }
    else  cout<<dp[n-1][n-1]<<endl;

}
