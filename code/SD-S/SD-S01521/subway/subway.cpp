#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int c,n,m,d0,q,w[N];
long long d[N][N];
void floyd()
{
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d0>>q;
	memset(d,0x1f,sizeof d);
	for(int i=1;i<=m;i++) d[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	while(n--)
	{
		int k,a[N],t[N];
		cin>>k;
		for(int i=1;i<=k;i++) cin>>a[i]>>t[i];
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				d[a[i]][a[j]]=min(d[a[i]][a[j]],(long long)(t[i]+t[j]));
			}
		}
	}
	floyd();
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<d[x][y]+w[x]+w[y]<<"\n";
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<d[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	return 0;
}
