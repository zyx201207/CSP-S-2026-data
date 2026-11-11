#include <bits/stdc++.h>
using namespace std;
int n,m,f[2010][2010],a[20010];
bitset <int> f[m];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[1][1]=a[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			f[i][j]=max(f[i][j],f[i-1][j-1]&a[i]);
		}
	}
	cout<<f[n][m];
	return 0;
}