#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=505;
int read()
{
	int f=1,k=0,c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+(c^48);
	return k*f;
}
int c,n,m,d,q;
ll w[N],f[M][M];
vector<pair<int,ll> > ve[N];
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(i!=j) f[i][j]=1e18;
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,x;i<=n;i++)
	{
		x=read();
		while(x--)
		{
			int a=read(),b=read();
			ve[a].push_back({i,b});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<ve[i].size();j++)
			for(int k=j+1;k<ve[i].size();k++)
			{
				pair<int,ll> a=ve[i][j],b=ve[i][k];
				f[a.first][b.first]=f[b.first][a.first]=min(f[b.first][a.first],a.second+b.second);
			}
	}
	floyd();
	while(q--)
	{
		int x=read(),y=read();
		ll ans=w[x]+w[y],mn=1e18;
		for(auto a:ve[x])
			for(auto b:ve[y])
				mn=min(mn,a.second+b.second+f[a.first][b.first]);
		cout<<ans+mn<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/