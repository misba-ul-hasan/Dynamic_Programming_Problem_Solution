//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    int dp[n+1][sum+1];
	    for(int i=0;i<=n;i++)
	    {
	       dp[i][0]=1;
	    }
	    for(int i=1;i<=sum;i++)
	    {
	        dp[0][i]=0;
	    }
	    int diff=sum;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(arr[i-1]<=j)
	            {
	                dp[i][j]=(dp[i-1][j] || dp[i-1][j-arr[i-1]]);
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	            if(dp[i][j])
	            {
	                int x=sum-j;
	                diff=min(diff,abs(x-j));
	            }
	        }
	    }
	    return diff;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends