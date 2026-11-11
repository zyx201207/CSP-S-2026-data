#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c,t,dis[N],n;
long long path[N],d,x[N];
bool is_fixed[N];
void dijkstra(int s)
{
	queue<int> q;
	for(int i = 1;i <= n;i++) dis[i] = n + 5;
	for(int i = 1;i <= n;i++) is_fixed[i] = false;
	for(int i = 1;i <= n;i++) path[i] = 0;
	dis[s] = 0;
	path[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		if(is_fixed[t]) continue;
		is_fixed[t] = true;
		for(int i = t + 1;i <= n;i++)
		{
			if(x[i] - x[t] > d) break;
			if(dis[i] > dis[t] + 1)
			{
				dis[i] = dis[t] + 1;
				q.push(i);
				path[i] = path[t];
			}
			else if(dis[i] == dis[t] + 1) path[i] += path[t];
		}
	} 
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		long long sum = 0;
		scanf("%d%lld",&n,&d);
		for(int i = 1;i <= n;i++) scanf("%lld",&x[i]);
		for(int i = 1;i <= n;i++)
		{
			dijkstra(i);
			for(int j = i + 1;j <= n;j++) if(path[j] == 2) sum++;
		}
		printf("%lld\n",sum);
	} 
	return 0;
} 
