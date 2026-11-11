#include<bits/stdc++.h> 
using namespace std;
long long int n,m,a[600000]={},t[600000]={},maxn=-1e9;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
	}
	sort(a+1,a+n+1);
	unsigned long long int sum=0;
	for(long long int i=1;i<=n;i++)
	{
		sum+=maxn-a[i];
	}
	if(sum<=m)
	{
		cout<<n;
		return 0;
	}
	long long int i=n;
	while(sum>m)
	{
		i--;
		sum-=i*(a[i+1]-a[i]);
	}
	printf("%lld",i);
	return 0;
}
