#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long ans[500010];
long long num[500010];
long long cnt[500010];
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1,cmp);
	/*for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"\n";
	}*/
	for(int i=1;i<=n;i++)
	{
		cnt[i]++;
		for(int j=1;j<i;j++)
		{
			num[i]+=a[i]-a[j];
			cnt[i]++;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(num[i]<=m)
		{
			cout<<cnt[i];
			break;
		}
	}
	return 0;
}
