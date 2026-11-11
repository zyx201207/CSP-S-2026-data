#include<bits/stdc++.h>
#define int long long
using namespace std;

int csd,n,m,md,q,x,y,op,last,f[4001][4001];

struct station
{
	int cnt;
	int value;
	int z[21];
	int v[21];
}a[500001];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>csd>>m>>n>>md>>q;
	for(int i=1;i<=n;++i) cin>>a[i].value;
	for(int i=1;i<=n+n*md;++i) for(int j=1;j<=n+n*md;++j) f[i][j]=0x7fffffff;
	for(int i=1;i<=m;++i)
	{
		cin>>op;
		last=0;
		for(int j=1;j<=op;++j)
		{
			cin>>x>>y;
			last=x;
			a[x].z[++a[x].cnt]=i;
			a[x].v[a[x].cnt]=y;
			if(j!=1)
			{
				f[last][x]=0;
				f[x][last]=0;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=a[i].cnt;++j)
		{
			f[i][n+(n-1)*md+j]=a[i].v[j];
			f[n+(n-1)*md+j][i]=a[i].v[j];
			for(int k=1;k<=a[i].cnt;++k)
			{
				if(k==j) continue;
				f[n+(n-1)*md+j][n+(n-1)*md+k]=0;
				f[n+(n-1)*md+k][n+(n-1)*md+j]=0;
			}
		}
	}
	for(int k=1;k<=n+n*md;++k)
	{
		for(int i=1;i<=n+n*md;++i)
		{
			for(int j=1;j<=n+n*md;++j)
			{
				if(f[i][k]==0x7fffffff||f[k][j]==0x7fffffff) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=1;j<=n;++j)
//		{
//			if(f[i][j]==0x7fffffff) cout<<"-1 ";
//			else cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--)
	{
		cin>>x>>y;
		cout<<f[x][y]+a[x].value+a[y].value<<endl;
	}
    return 0;
}













