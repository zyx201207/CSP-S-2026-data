#include <bits/stdc++.h>
using namespace std;
#define llo long long
const int N=510,M=5e5+10;
const llo ma=1000000000000000000ll;
int ccc,n,m,d[M],q,a[M][22],c[M][22];
llo w[N][N],f[N][N],p[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>ccc>>n>>m>>d[0]>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)w[i][j]=ma;
	for(int i=1;i<=m;i++)cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		w[i][i]=0;
		int k;cin>>k;
		while(k--)
		{
			int b;
			cin>>b;
			cin>>c[b][++d[b]];
			a[b][d[b]]=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<d[i];j++)
		{
			for(int k=j+1;k<=d[i];k++)
			{
				w[a[i][j]][a[i][k]]=w[a[i][k]][a[i][j]]=min(w[a[i][j]][a[i][k]],0ll+c[i][j]+c[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				w[j][k]=min(w[j][k],w[j][i]+w[k][i]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		llo ans=ma;
		for(int i=1;i<=d[x];i++)
		{
			for(int j=1;j<=d[y];j++)
			{
				ans=min(ans,w[a[x][i]][a[y][j]]+c[x][i]+c[y][j]);
			}
		}
		cout<<ans+p[x]+p[y]<<endl;
	}
	return 0;
}