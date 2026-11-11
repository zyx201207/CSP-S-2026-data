#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn;
long long a[500005];
bool cmp(int x,int y)
{
	return x>=y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		long long sum=0,ans=1;
		for(int j=i+1;j<=n;j++)
		{
			sum+=a[i]-a[j];
			if(sum>m)
			{
				break;
			}
			ans++;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
