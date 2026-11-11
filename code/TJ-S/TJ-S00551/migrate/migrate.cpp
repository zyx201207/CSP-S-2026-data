#include <bits/stdc++.h>
using namespace std;
int zd(int x,int y,int b[])
{
	return ((b[x]/y)%2==0)+((b[1]/y)%2==0);
}
int main ()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m;
		cin>>n>>m;
		int a[n];
		for(int j= 1;j<=n;j++)
		{
			cin>>a[i];
		}
		int maxn = -1e9;
		for(int j= 1;j<=n;j++)
		{
			maxn = max(maxn,zd(j,m,a));
		}
		cout<<maxn-(i%2==1)<<endl;
	}
	
}

