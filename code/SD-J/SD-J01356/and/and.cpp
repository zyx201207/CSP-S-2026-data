#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxx=-0x3f3f3f3f,a[200005],ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i]&=a[i+j];
			maxx=max(maxx,a[i]);
		}
	}
	cout<<maxx;
	return 0;
}
/*
4 2
3 15 12 12
*/
