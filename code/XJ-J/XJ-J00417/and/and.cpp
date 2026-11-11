#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int a[N];
int sum[N][1005];
int cnt;
int query(int z,int f,int j,int q)
{
	int cnt=0;
	for(int i=1;i<=q;i++)
	{
		if(i==f) continue;
		sum[++cnt][j]=sum[i][j-1]&z;
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i][1]=a[i];
	}
	int maxx=-1;
	int q=n;
	for(int j=2;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			q=query(a[i],i,j,q);
//			for(int q=1;q<=n;q++) cout<<sum[q][j]<<" ";
//			cout<<endl;
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(sum[i][m]>maxx)
		{
			maxx=max(maxx,sum[i][m]);
		}
	}
	cout<<maxx;
	return 0;
}
