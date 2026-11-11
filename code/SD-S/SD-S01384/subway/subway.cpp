#include<bits/stdc++.h>
//题目 给定一个特殊图，每个A点外联若干个 B点，且保证每个 B 点的度数不超过20
//多次查询两个 B 点间的最短路
//对于每个 A 点，枚举其所有相邻 B 点的相邻 A 点
//floyd 跑出两个 A 点间的最短路
//对于每个 询问，枚举两B点通过哪两个 A 点相连即可
//建图：对于每个 A 点，不超过其所连的所有 B 点个数乘20
//每次查询 20^2
//最短路 n^3
//thinked by 14:56 
//done by 15:13 546ms
using namespace std;
#define ll long long
int read()
{
	int x=0,flag=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')flag=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*flag;
}
const int N = 505 ;
const int M = 5e5+5;
ll f[N][N];
int w[M];
struct node{
	int v,w;
};
vector<node> g[M];
int main()
{
	int st=clock();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int k = read();
		while(k--)
		{
			int a=read(),t=read();
			for(node p:g[a])
			{
				int v=p.v,w=p.w;
				f[i][v]=f[v][i]=min(f[i][v],(ll)(w+t));
			}
			g[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)if(i^k)
		{
			for(int j=1;j<=n;j++)if(j^i&&j^k)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	while(q--)
	{
		ll ans=1e18;
		int u=read(),v=read();
		for(node u1:g[u])
		{
			for(node v1:g[v])
			{
				ans=min(ans,u1.w+v1.w+f[u1.v][v1.v]);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	int ed=clock();
//	cerr<<ed-st<<"ms"<<endl;
	return 0;
}

