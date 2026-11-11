#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long g[500005];//sl
long long y[500005];//sy
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(1+a,a+1+n);
	long long p=0;
	y[0]=m;
	g[0]=0;
	for (int i=1;i<=n;i++)
	{
		long long llg=g[i-1]+1;
		long long lly=y[i-1]-g[i-1]*(a[i]-a[i-1]);
		
		while (lly<0)
		{
			p++;
			llg--;
			lly+=a[i]-a[p];
		}
		g[i]=llg;
		y[i]=lly;
	}
	long long maxx=-1;
	for (int i=1;i<=n;i++)
	{
	//	cout<<g[i]<<" "<<y[i]<<"\n";
		maxx=max(maxx,g[i]);
	}
	cout<<maxx;
	return 0;
} 