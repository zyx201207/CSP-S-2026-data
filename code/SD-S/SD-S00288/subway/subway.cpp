#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline int read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*=f;
}
int ou[20],pt;
inline void print(ll x)
{
	if(x==0) ou[++pt]=0;
	while(x) ou[++pt]=x%10,x/=10;
	while(pt) putchar(ou[pt--]^48);
	putchar('\n');
}

const int N=505,M=501000;
int c,n,m,d,q,w[M];
vector<pair<int,ll> > vc[M]; // 每个站台有哪些线路
ll f[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=m;i++) read(w[i]);//,vc[i].reserve(20);
	for(int i=1,k;i<=n;i++)
	{
		read(k);
		for(int j=1,a,t;j<=k;j++)
		{
			read(a);read(t);
			vc[a].push_back({i,(ll)t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(auto x:vc[i])
			for(auto y:vc[i])
			{
				int u=x.first,v=y.first;
				ll W=x.second+y.second;
				if(u^v) f[u][v]=f[v][u]=min(f[u][v],W);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
	for(int x,y;q--;)
	{
		read(x);read(y);
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto u:vc[x])
			for(auto v:vc[y])
			{
				int U=u.first,V=v.first;
				ans=min(ans,f[U][V]+u.second+v.second+w[x]+w[y]);
			}
		print(ans);
	}
	return 0;
}
