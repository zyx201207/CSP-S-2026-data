#include<bits/stdc++.h>
using namespace std;
const int Max = 5e5+5,Vax = 6e5;
int C,N,M,D,Q;
long long W[Max+5];
vector<pair<int,long long> > Edge[Vax+5];
long long Dis[Vax+5];
int X[Max+5],Y[Max+5];
long long ans[Max+5];
void Dijk(int str)
{
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	q.push({0,str});
	memset(Dis,0x3f,sizeof(Dis));
	Dis[str] = 0;
	while(!q.empty())
	{
		auto top = q.top();
		q.pop();
		int at = top.second;long long dis = top.first;
		if(dis != Dis[at]) continue;
		for(auto i : Edge[at])
		{
			int to = i.first;long long w = i.second;
			if(Dis[to] > dis+w)
			{
				Dis[to] = dis+w;
				q.push({dis+w,to});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&N,&M,&D,&Q);
	for(int i = 1;i <= M;i++) scanf("%lld",W+i);
	for(int i = 1;i <= N;i++)
	{
		int K;
		scanf("%d",&K);
		for(int j = 1;j <= K;j++)
		{
			int a;
			long long w;
			scanf("%d%lld",&a,&w);
			Edge[a].push_back({i+M,w});
			Edge[i+M].push_back({a,w});
		}
	}
	for(int i = 1;i <= Q;i++)
		scanf("%d%d",X+i,Y+i),ans[i] = 9e18;
	for(int i = 1;i <= N;i++)
	{
		Dijk(i+M);
		for(int j = 1;j <= Q;j++)
			ans[j] = min(ans[j],Dis[X[j]]+Dis[Y[j]]+W[X[j]]+W[Y[j]]);
	}
	for(int i = 1;i <= Q;i++)
	{
		printf("%lld\n",ans[i]);
		// else printf("-1\n");
	}
	return 0;
}