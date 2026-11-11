#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;
int c, n, m, z, q, w[500100], d[500100], a[500100][2];
vector<PII> g[500100];
priority_queue<PII, vector<PII>, greater<PII> > p;
bool st[500100];
inline int dijkstra(int s, int t){
	while(p.size())
		p.pop();
	memset(d, 0x3f, sizeof(d));
	memset(st, false, sizeof(st));
	st[s] = true, d[s] = 0;
	p.push({0, s});
	while(p.size()){
		int x = p.top().second;
		p.pop();
		for ( int h = 0; h < g[x].size(); h++ ){
			int to = g[x][h].second, cost = g[x][h].first;
			if ( d[to] > d[x] + cost && !st[to] ){
				d[to] = d[x] + cost;
				p.push({d[to], to});
				st[to] = true;
			}
		}
	}
	return d[t];
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &z, &q);
    for ( int i = 1; i <= m; i++ )
    	scanf("%d", &w[i]);
    for ( int i = 1; i <= n; i++ ){
    	int k;
    	scanf("%d", &k);
    	for ( int j = 1; j <= k; j++ )
    		scanf("%d%d", &a[j][0], &a[j][1]);
		for ( int j = 1; j <= k; j++ )
			for ( int l = j + 1; l <= k; l++ )
				g[a[j][0]].push_back({a[j][1] + a[l][1], a[l][0]});
	}
	while(q--){
		int s, t;
		scanf("%d%d", &s, &t);
		printf("%d\n", dijkstra(s, t) + w[s] + w[t]);
	}
    return 0;
}
