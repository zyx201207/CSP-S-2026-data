#include <bits/stdc++.h>
using namespace std;

long long a[5000010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long maxn=0;
	for(int i=1;i<=n;i++)
	{
		long long ans=1;
		int x=m;
		for(int j=i-1;j>=1&&x>=0;j--)
		{
			x-=a[i]-a[j];
			if(x>=0)
			{
				ans++;
			
			}
		}
		maxn=max(ans,maxn);
	}
	cout<<maxn;
	return 0;
 }
