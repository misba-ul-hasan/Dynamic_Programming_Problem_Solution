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
void solve(int tc)
{
    ll n,q;
    cin>>n>>q;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll dp[n+1][21];
    for(ll i=1;i<=n;i++)
    {
        dp[i][0]=a[i];
    }
    for(ll i=n;i>=1;i--)
    {
        for(ll j=1;j<=20;j++)
        {
            if((i+(1LL<<j))<=n)
            {
                dp[i][j]=gcd(dp[i][j-1],dp[i+(1LL<<(j-1))][j-1]);
            }
        }
    }
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        ll ans=a[l];
        for(ll j=20;j>=0;j--)
        {
            if((l+(1LL<<j))<=r){
                ans=gcd(ans,dp[l][j]);
                l+=(1LL<<j);
            }
        }
        ans=gcd(ans,a[r]);
        cout<<ans<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc=1;
    solve(tc);
    return 0;
}