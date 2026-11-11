#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll read()
{
	char ch = getchar();
	ll num = 0,sign = 1;
	while(ch<'0'||ch>'9')sign = (ch == '-'?-1:1),ch = getchar();
	while(ch >= '0'&&ch <= '9')num = (num<<3)+(num<<1)+(ch-'0'),ch = getchar();
	return sign>0?num:-num;
}
const int N = 5e2+8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
vector<pair<int,int>>adj[N*2000];
int c,n,m,d,q,w[N*1000],k[N],prea,cnt[N*1000],ncn;
ll dis[N*1000];
bool vis[N*1000];
void dijikstra(int s)
{
	priority_queue<pair<int,int>>pq;
	dis[s] = 0,pq.push({0,s});
	while(!pq.empty())
	{
		auto a = pq.top();
		pq.pop();
		int u = a.second;
		if(vis[u])continue;
		vis[u] = 1;
		for(auto a:adj[u])
		{
			int v = a.first,w = a.second;
			if(vis[v])continue;
			if(dis[v] > dis[u]+w)dis[v] = dis[u]+w,pq.push({-dis[v],v});
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(),n = read(),m = read(),d = read(),q = read(),ncn = m;
	for(int i = 1;i <= m;i++)w[i] = read(),cnt[i] = 1;
	for(int i = 1;i <= n;i++)
	{
		k[i] = read();
		for(int j = 1,a,t;j <= k[i];j++){
			a = read(),t = read();
			if(j == 1){
				adj[++ncn].push_back({a,t}),adj[a].push_back({ncn,t}),prea = ncn,cnt[a]++;
				continue;
			}
			adj[prea].push_back({++ncn,0}),adj[ncn].push_back({a,t}),adj[a].push_back({ncn,t});
			prea = ncn,cnt[a]++;
		}
	}
	for(int i = 1,x,y;i <= q;i++)
	{
		x = read(),y = read();
		memset(dis,INF,sizeof(dis)),memset(vis,0,sizeof(vis));
		dijikstra(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}

