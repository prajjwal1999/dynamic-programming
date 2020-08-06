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
bool subset_Sum(int *arr,int sum,int n)
{
  bool dp[n+1][sum+1];
  for(int i=0;i<n;i++)
    dp[i][0]=true;
  for(int i=0;i<sum+1;i++)
    dp[0][i]=false;
  dp[0][0]=true;
  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<sum+1;j++)
    {
      if(arr[i-1]<=j)
        dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
      else
        dp[i][j]=dp[i-1][j];
    }
  }
  return dp[n][sum];
}
 

int  main()
{
  c_p_c();
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  int sum;cin>>sum;
  if(subset_Sum(arr,sum,n))
    cout<<"true";
  else
    cout<<"false";
  

 


  return 0;
    
}