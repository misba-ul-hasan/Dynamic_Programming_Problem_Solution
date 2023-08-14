#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s,s1;
    cin>>s;
    s1=s;
    ll n=s.size();
    ll dp[n+1][n+1];
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(s[i-1]==s1[j-1] && i!=j)
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}