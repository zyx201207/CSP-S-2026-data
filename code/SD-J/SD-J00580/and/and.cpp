#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e3+5;
const int INF=0x3f3f3f3f;
LL n,m;
LL a[N];
LL dp[N][N];//在前i个数中选择出j个数的按位与最大值 
LL sum,ans=15;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=max(a[i],sum);
		ans=a[i]&ans;
	}
	if(m==1)
	{
		cout<<sum;
		return 0;
	}
	if(m==n)
	{
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		LL maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				maxx=max(maxx,a[i]&a[j]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1)
	{
		LL maxx=0;
		for(int i=1;i<=n;i++)
		{
			ans=15;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				ans&=a[j];
			}
			maxx=max(ans,maxx);
		}
		cout<<maxx;
		return 0;
	}
	return 0;
 } 
 /*
4 2
3 15 12 12
 
5 3
31 3 1 15 7
 */
