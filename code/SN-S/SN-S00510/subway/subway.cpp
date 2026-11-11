//徐语瞳 SN-S00510 西安翱翔中学
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
long long f[505][505];
vector<pair<int,int>> A[500005];
int read()
{
	int res=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) res=(res<<1)+(res<<3)+(ch-'0'),ch=getchar();
	return res;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k;
		k=read();
		for(int j=1;j<=k;j++)
		{
			int a,t;
			a=read(),t=read();
			A[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) f[i][j]=1e18;
			else f[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto &it:A[i])
		{
			for(auto &itt:A[i])
			{
				int nx=it.first,nxx=itt.first,nw=it.second,nww=itt.second;
				f[nx][nxx]=min(f[nx][nxx],1ll*(nw+nww));
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;
		x=read(),y=read();
		long long ans=1e18;
		for(auto &it:A[x])
		{
			for(auto &itt:A[y])
			{
				int nx=it.first,nxx=itt.first,nw=it.second,nww=itt.second;
				ans=min(f[nx][nxx]+nw+nww,ans);
			}
		}
		cout<<(ans+w[x]+w[y])<<"\n";
	}
	return 0;
}
