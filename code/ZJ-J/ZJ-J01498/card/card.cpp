#include<bits/stdc++.h>
using namespace std;
#define int long long
	long long ans[500002];
int32_t main()
{
     freopen("card.in","r",stdin);
     freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n+1];
     int s=0;
     a[0]=-100;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])s=0;
	}
	if(s==1)
	{
		map<long long,long long>dp;
		for(long long i=1;i<=n;i++)
		{
			dp[a[i]]=max(dp[a[i]],i);
		}
		for(int i=1;i<=m;i++)
		{
            cout<<dp[i]<<" ";
		}
		return 0;
	}
       for(int l=1;l<=n;l++)
       {
       	  	bool v[n];
	 	  memset(v,0,sizeof(v));
	 	  for(int i=l;i<=n;i++)
	 	  {
             for(int j=i-1;j>=l;j--)
             {
               if(a[j]==a[i]&&v[j]==0)
			   {
			   	 for(int k=j;k<i;k++)v[k]=1;
			   }             	
			 }
		  }
		  for(int ik=l;ik<=n;ik++)
		  {
		  	 if(v[ik]==0)ans[a[ik]]++;
		  }
	   }
      		  for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
														                                                                
	return 0;
}
//