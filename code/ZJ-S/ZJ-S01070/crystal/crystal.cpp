#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[1010101],ans[1010101],maxn=-1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[i]=ans[i-1]+a[i];
	}
	a[n+1]=m+1;
	sort(a+1,a+1+n);
	int j=1;
	for(int i=1;i<=n+1;i++)
	{
		sum+=abs((i-j)*(a[i]-a[i-1]));
		if(sum>m)
		{
			maxn=max(maxn,i-j);
			sum-=a[i]-a[j];
			j++;
		}
	}
	/*if(sum<=m)
	{
		maxn=n-j;
	} */
	cout<<maxn;
}
