#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD=1e9+7;
#define endl '\n'
#define F first
#define S second
const double PI = 3.141592653589793238460;

  void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
    #endif
}
ll dp[100][100];
ll knapsack(ll wt[],ll val[],ll W,ll n)
{
  if(n==0 || W==0)
    return 0;
  if(dp[n][W]!=-1)
    return dp[n][W];
  if(wt[n-1]<=W)
    return dp[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
  else if(wt[n-1]>W)
    return dp[n][W]=knapsack(wt,val,W,n-1);
}

int  main()
{
  c_p_c();
  ll n,W;cin>>n>>W;
  ll wt[n],val[n];
  memset(dp,-1,sizeof(dp));
  for(ll i=0;i<n;i++)cin>>val[i];
    for(ll i=0;i<n;i++)cin>>wt[i];
  cout<<knapsack(wt,val,W,n);



  return 0;
}