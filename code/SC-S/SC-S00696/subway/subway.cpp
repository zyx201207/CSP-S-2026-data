#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
long long w[500010], rode[510][510], mi[510][510];
vector <pair <int, long long> > go[500010], come[500010], to[500010];

void dist (int start){
	priority_queue <pair <long long, int>, vector <pair <long long, int> >, greater <pair <long long, int> > > pq;
	pq.push ({0ll, start});
	while (!pq.empty ()){
		long long x = pq.top ().first;
		int i = pq.top ().second;
		pq.pop ();
		if (mi[start][i] < x){
			continue ;
		}
		for (auto y : to[i]){
			if (x + y.second < mi[start][y.first]){
				pq.push ({x + y.second, y.first});
				mi[start][y.first] = x + y.second;
			}
		}
	}
}

int main (){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++){
		scanf ("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++){
		int k, a;
		long long t;
		scanf ("%d", &k);
		for (int j = 1; j <= k; j++){
			scanf ("%d%lld", &a, &t);
			go[a].push_back ({i, t});
			come[i].push_back ({a, t});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			rode[i][j] = LONG_LONG_MAX;
	for (int i = 1; i <= n; i++){
		for (auto y : come[i]){
			for (auto u : go[y.first]){
				if (u.first <= i)
					continue ;
				rode[i][u.first] = min (rode[i][u.first], y.second + u.second);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (rode[i][j] != LONG_LONG_MAX){
				to[i].push_back ({j, rode[i][j]});
				to[j].push_back ({i, rode[i][j]});
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				mi[i][j] = LONG_LONG_MAX;
	for (int i = 1; i <= n; i++){
		dist (i);
	}
//	for (int i = 1; i <= n; i++){
//		printf ("%d ", i);
//		for (int j = 1; j <= n; j++){
//			printf ("%lld ", mi[i][j]);
//		}
//		printf ("\n");
//	}
	while (q--){
		int a, b;
		scanf ("%d%d", &a, &b);
		long long ans = LONG_LONG_MAX;
		for (auto y : go[a]){
			for (auto u : go[b]){
				ans = min (ans, mi[y.first][u.first] + u.second + y.second);
			}
		}
		printf ("%lld\n", ans + w[a] + w[b]);
	}
	return 0;
}