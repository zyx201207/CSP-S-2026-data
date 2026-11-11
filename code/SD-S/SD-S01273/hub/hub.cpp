#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
#include <queue>
typedef unsigned long long ull;
typedef long long ll;
const ull N=1000010;
ull T,n,k;
std::vector<ull> g[N];
ull ans;
void dfs000(ull p)
{
	static ull ps[13],vis[13];
	if(p>k)
	{
		static ull dis[13],q[13];
		ull cnt=0;
		for(ull i(1);i<=n;++i) for(ull j:g[i]) if(vis[i]&&vis[j]) ++cnt;
		if(cnt<2*(k-2)) return;
		for(ull i(1);i<=n;++i) dis[i]=~0ull;
		ull hd=1,tl=0;
		for(ull i(1);i<=k;++i) q[++tl]=ps[i],dis[ps[i]]=0;
		while(hd<=tl)
		{
			ull u=q[hd++];
			for(ull v:g[u]) if(!~dis[v]) dis[v]=dis[u]+1,q[++tl]=v;
		}
		ans=std::min(ans,dis[q[n]]);
		return ;
	}
	for(ull i(1);i<=n;++i) if(!vis[i]) ps[p]=i,vis[i]=1,dfs000(p+1),vis[i]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%*u%llu",&T);
	while(T--)
	{
		scanf("%llu%llu",&n,&k);
		for(ull i(1);i<=n;++i) g[i].resize(0);
		for(ull i(1),u,v;i<n;++i)
		{
			scanf("%llu%llu",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==n)
		{
			puts("0");
			continue;
		}
		if(k==n-1||k==n-2)
		{
			puts("1");
			continue;
		}
		if(k<=7&&n<=10)
		{
			ans=0x3f3f3f3f3f3f3f3f;
			dfs000(1);
			printf("%llu\n",ans);
			continue;
		}
		n=(n-1)/2;
		if(k>=n)
		{
			puts("1");
			continue;
		}
		n=(n+1)/2;
		k=(k+1)/2;
		printf("%llu\n",(n-k+1)/2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
