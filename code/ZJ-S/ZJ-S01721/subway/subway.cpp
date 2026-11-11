#include<bits/stdc++.h> 
using namespace std;
long long n,m,gm,d,q;
long long s=0;
long long w[510],a[510][510],b[510][510],x[510],y[510];
long long f[10010][10010],p[510][10010],o[10010][10010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>gm>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>b[i][j];
			f[0][a[i][j]]=b[i][j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int kk=1;kk<=k;kk++)
			{
				f[a[i][j]][a[i][kk]]=b[i][kk];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
	}
	for(int kk=1;kk<=m;kk++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j]=min(f[i][j],f[i][kk]+f[0][kk]+f[kk][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long l=f[x[i]][y[i]]+w[x[i]]+w[y[i]];
		l+=f[0][x[i]];
		cout<<l;
		cout<<'\n';
	}
	return 0;
}