#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100000];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=0,z=0,g=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=[i];
		z=a[i]-a[i+1];
		if(z<=m)
		{
			g=g+1
		}
	}
	cout<<g;
	return 0;
}
