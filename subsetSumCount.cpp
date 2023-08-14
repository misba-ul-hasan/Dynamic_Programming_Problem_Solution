//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define pb push_back
#define eb emplace_back
#define mod 1000000007
#define maxN 1000005
#define endl '\n'
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pii pair<ll,ll>
#define dekhao(tc,ans) cout<<"Case "<<tc<<": "<<ans<<"\n"
#define google(tc,ans) cout<<"Case #"<<tc<<": "<<ans<<"\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
#define bitcount __builtin_popcountll
#define min_heap priority_queue<ll,vector<ll>,greater<ll>>
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const double pi=acos(-1.0);
#define INF 1e18
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll binpow(ll b,ll p){ll res=1;while(p){if(p%2==0){b*=b;p/=2;}else{res*=b;p--;}}return res;}
ll binpowwithmod(ll b,ll p){ll res=1;while(p){if(p%2==0){b=(b%mod*b%mod)%mod;p/=2;}else{res=(res%mod*b%mod)%mod;p--;}}return (res%mod);}
ll dx[]={+1,+0,+0,-1};
ll dy[]={+0,-1,+1,+0};
ll a[10005],dp[1005][100005];
ll n,sum;
ll goriberDP(ll n,ll sum)
{
    if(n<0)
    {
        if(sum==0)
        {
            return 1;
        }
        return 0;
    }
    if(sum==0)
    {
        return 1;
    }
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(a[n]<=sum)
    {
        return dp[n][sum]=goriberDP(n-1,sum-a[n])+goriberDP(n-1,sum);
    }
    return dp[n][sum]=goriberDP(n-1,sum);
}
void solve(int tc)
{
    cin>>n>>sum;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<goriberDP(n-1,sum)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc=1;
    int t;
    cin>>t;
    while(t--)
    {
        solve(tc);
        tc++;
    }
    //solve(tc);
    return 0;
}