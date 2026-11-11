#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
#include <queue>
#include <utility>
typedef unsigned long long ull;
typedef long long ll;
const ull N=510,M=500010,Q=100010,inf=0x3f3f3f3f3f3f3f3f;
ull n,m,d,q;
ull w[M];
ull ds[N][N];
std::vector<std::pair<ull,ull>> stt[M];
ull dis[N];
ull qx[Q],qy[Q],ans[Q];
std::vector<ull> iqx[M];
inline ull min(ull x,ull y) { return x<y?x:y; }
ull read()
{
	ull x=0; char ch=getchar();
	while('0'>ch||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	scanf("%*u%llu%llu%llu%llu",&n,&m,&d,&q);
	read();n=read();m=read();d=read();q=read();
	for(ull i(1);i<=m;++i) w[i]=read();// scanf("%llu",&w[i]);
	for(ull i(1);i<=n;++i) for(ull j(1);j<=n;++j) ds[i][j]=(i==j?0:inf);
	for(ull i(1);i<=m;++i) stt[i].reserve(d);
	for(ull i(1);i<=n;++i)
	{
		ull k;
//		scanf("%llu",&k);
		k=read();
		for(ull j(1);j<=k;++j)
		{
			ull v,t;
			v=read();t=read();
//			scanf("%llu%llu",&v,&t);
			for(std::pair<ull,ull> pr:stt[v])
			{
				ds[i][pr.first]=min(ds[i][pr.first],pr.second+t);
				ds[pr.first][i]=ds[i][pr.first];
			}
			stt[v].emplace_back(i,t);
		}
	}
	for(ull k(1);k<=n;++k)
	{
		for(ull i(1);i<=n;++i)
		{
			for(ull j(1);j<=n;++j)
			{
				ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
			}
		}
	}
	for(ull i(1);i<=q;++i)
	{
//		scanf("%llu%llu",&qx[i],&qy[i]);
		qx[i]=read();qy[i]=read();
		iqx[qx[i]].push_back(i);
	}
	for(ull j(1);j<=m;++j)
	{
		if(iqx[j].empty()) continue;
		for(ull i(1);i<=n;++i)
		{
			dis[i]=inf;
			for(std::pair<ull,ull> pr:stt[j])
			{
				dis[i]=min(dis[i],ds[i][pr.first]+pr.second);
			}
		}
		for(ull qid:iqx[j])
		{
			ans[qid]=inf;
			for(std::pair<ull,ull> pr:stt[qy[qid]])
				ans[qid]=min(ans[qid],dis[pr.first]+pr.second);
		}
	}
	for(ull i(1);i<=q;++i) printf("%llu\n",w[qx[i]]+w[qy[i]]+ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
i - j

*/
