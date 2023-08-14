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
#define maxN 100005
#define endl '\n'
#define all(x) x.begin(),x.end()
#define dekhao(tc,ans) cout<<"Case "<<tc<<": "<<ans<<"\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
#define min_heap priority_queue<ll,vector<ll>,greater<ll>>
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const double pi=acos(-1.0);
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll binpow(ll b,ll p){ll res=1;while(p){if(p%2==0){b*=b;p/=2;}else{res*=b;p--;}}return res;}
ll dx[]={+1,+0,+0,-1};
ll dy[]={+0,-1,+1,+0};
ll val[1000],wt[1000];
ll dp[1000][1000];
ll knapsack(ll w,ll n)
{
    if(n==0 || w<0)
    {
        return 0;
    }
    if(dp[n-1][w]!=-1)
    {
        return dp[n-1][w];
    }
    if(wt[n-1]>w)
    {
        return dp[n-1][w]=knapsack(w,n-1);
    }
    return dp[n-1][w]=max((val[n-1]+knapsack(w-wt[n-1],n-1)),knapsack(w,n-1));
}
void solve(int tc)
{
    memset(dp,-1,sizeof(dp));
    ll n,w;
    cin>>n>>w;
    for(ll i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    cout<<(knapsack(w,n))<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc=1;
    solve(tc);
    return 0;
}