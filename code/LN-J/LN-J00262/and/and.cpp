#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int b[200005];
int maxx;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i]=a[i] & a[j];
			b[i]=max(a[i],b[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(b[i],maxx);
	}
	cout<<maxx;
	return 0;
}
