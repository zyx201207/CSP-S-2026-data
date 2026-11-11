#include <iostream>
#include <algorithm>
using namespace std;
long long dp[2005][2005];
long long n,m,a[200005],maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	  {
	  	cin>>a[i];
	  	dp[i][1]=a[i];
	  }
	if(n==m)
	  {
	  	long long s=a[1];
	  	for(i=2;i<=n;i++)
	  	  {
	  	  	s=s&a[i];
		  }
		cout<<s;
		return 0;
	  }
	for(i=2;i<=m;i++)
	  {
	  	for(j=i;j<=n;j++)
	  	  {
	  	  	for(k=i-1;k<j;k++)
	  	  	  {
	  	  	  	dp[j][i]=max(dp[j][i],a[j]&dp[k][i-1]);
			  }
		  }
	  }
	for(i=m;i<=n;i++)
	  {
	  	maxn=max(maxn,dp[i][m]);
	  }
	cout<<maxn;
	return 0;
}
