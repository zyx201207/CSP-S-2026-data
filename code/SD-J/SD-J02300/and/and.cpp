#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[200005];
int maxn=-1;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		int ans=0;
		for(int i=2;i<=n;i++)
		{
			a[i]=a[i-1]&a[i];
		}
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		maxn=-1;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	int ans;
	sort(a+1,a+1+n);
	for(int i=n;i<=n-m+1;i++)
	{
		a[i]=a[i]&a[i-1];
	}
	cout<<a[n-m+1];
	return 0;
}

