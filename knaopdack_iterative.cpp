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


int  main()
{
  c_p_c();
  int n,W;cin>>n>>W;
  vector<int> val(n),wt(n);
  for(int i=0;i<n;i++) cin>>val[i];
  for(int i=0;i<n;i++) cin>>wt[i];
  int dp[n+1][W+1];
memset(dp,-1,sizeof(dp));

  for(int i=0;i<n+1;i++)
        dp[0][i]=0;
  for(int i=0;i<W+1;i++)
        dp[i][0]=0;
   for(int i=1;i<n+1;i++)
   {
    for(int j=1;j<W+1;j++)
    {
      if(wt[i-1]<=j)
        dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
      else
        dp[i][j]=dp[i-1][j];


    }
   }  
   cout<< dp[n][W];

 


  return 0;
    
}