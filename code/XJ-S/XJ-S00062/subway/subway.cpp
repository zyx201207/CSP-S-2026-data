#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
struct node{
	int v;long long w;
};
int c,n,m,d,p,t[510][5010];//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数。
long long w[N],dist[N];
vector <node> edge[510];
void dij(int s)
{
	memset(dist,0,sizeof(dist));
	priority_queue <pair<int , int> >  vector<pair<int , int> > , greater<pair<int , int> > > q;
	q.push({0,s})
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;cin >> k;
		int tmp1,tmp2,c1,c2;
		cin >> tmp1 >> c1 >> tmp2 >> c2;
		edge[tmp1].push_back({tmp2,c1+c2});
		edge[tmp2].push_back({tmp1,c1+c2});
	}
	while(p--){
		int u,v;
		cin >> u >> v;
		dij(u);
		cout << dist[v]+w[u]+w[v] << "\n";
	}
	return 0;
}
