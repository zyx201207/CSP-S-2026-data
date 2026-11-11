#include<bits/stdc++.h>
//#define getchar_unlocked _getchar_nolock
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
vector<int>a[500005];
vector<int>can[500005];
int in[500005],top[500005];
ll dis[505][505];
int n,m,q,c,d;
inline int read()
{
	int ch=getchar_unlocked();
	int f=1,c=0;
	while(ch!='-'&&(ch>'9'||ch<'0')&&ch!=EOF)ch=getchar_unlocked();
	if(ch==EOF)return 0;
	if(ch=='-')f=-1,ch=getchar_unlocked();
	while(ch>='0'&&ch<='9')c=c*10+ch-'0',ch=getchar_unlocked();
	return c*f;
}
inline void write(ll x)
{
	if(x>=10LL)
	{
		write(x/10LL);
	}
	putchar('0'+x%10LL);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		in[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		k=read();
		for(int j=1;j<=k;j++)
		{
			ll v,w;
			v=read();
			w=read();
			can[v].push_back(i);
			a[v].push_back(w);
		}
	}
	memset(dis,inf,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n';
	for(int k=1;k<=m;k++)
	{
		for(int i=0;i<can[k].size();i++)
		{
			for(int j=0;j<can[k].size();j++)
			{
				if(i==j)continue;
				dis[can[k][i]][can[k][j]]=min(dis[can[k][i]][can[k][j]],0LL+a[k][i]+a[k][j]);
				dis[can[k][j]][can[k][i]]=dis[can[k][i]][can[k][j]];
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n';
	// floyd
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k)continue;
			for(int j=1;j<=n;j++)
			{
				if(i==j||j==k)continue;
				if(dis[k][j]==inf||dis[i][k]==inf)continue;
				if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n';
	for(int i=1;i<=q;i++)
	{
		int l,r;
		ll ans=LLONG_MAX;
		l=read(),r=read();
		for(int _l=0;_l<can[l].size();_l++)
		{
			for(int _r=0;_r<can[r].size();_r++)
			{	
				int ro=can[r][_r],lo=can[l][_l];
				if(dis[lo][ro]==inf)continue;
				ans=min(ans,dis[lo][ro]+in[l]+in[r]+a[l][_l]+a[r][_r]);
			}
		}
		write(ans);
		putchar('\n');
	}
    return 0;
}