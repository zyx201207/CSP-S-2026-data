#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+5;

int __c, T;
int n;
long long d;
long long a[N];

namespace sub1_10 {
	vector<int> e[5005];
	int dist[5005][5005];
	int sum[5005][5005];
	queue<pair<int, int> > q;
};

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &__c, &T);
	while (T--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", a+i);
		long long dx = a[2]-a[1];
		bool f = true;
		for (int i = 2; i < n; i++)
			if (a[i+1]-a[i] != dx) {
				f = false;
				break;
			}
		if (f) {
			if (d <= dx)
				puts("0");
			else
				printf("%lld\n", max(d/dx, 0ll)); 
		} else {
			if (n <= 5000) {
				using namespace sub1_10;
				for (int i = 1; i <= n; i++)
					e[i].clear();
				for (int i = 1; i <= n; i++)
					for (int j = i+1; j <= n; j++)
						if (a[j]-a[i] <= d) {
							e[i].push_back(j);
							e[j].push_back(i);
						}
				memset(dist, -1, sizeof dist);
				memset(sum, 0, sizeof sum);
				for (int i = 1; i <= n; i++) {
					q.push({i, 0});
					dist[i][i] = 0;
					sum[i][i] = 1;
					while (!q.empty()) {
						pair<int, int> u = q.front();
						q.pop();
						for (int v : e[u.first]) {
							if (dist[i][v] == -1 || dist[i][u.first]+1 < dist[i][v]) {
	//							printf("update %d\n", v);
								q.push({v, sum[i][v]});
								sum[i][v] = sum[i][u.first];
								dist[i][v] = dist[i][u.first]+1;
							} else if (dist[i][u.first]+1 == dist[i][v]) {
	//							printf("update %d\n", v);
								q.push({v, sum[i][v]});
								if (sum[i][v] <= 10)
									sum[i][v] += sum[i][u.first]-u.second;
							}
						}
					}
				}
	//			for (int i = 1; i <= n; i++) {
	//				for (int j = i+1; j <= n; j++)
	//					printf("%d ", sum[i][j]);
	//				puts("");
	//			}
				int ans = 0;
				for (int i = 1; i <= n; i++)
					for (int j = i+1; j <= n; j++)
						if (sum[i][j] == 2)
							++ans;
				printf("%d\n", ans);
			} else {
				puts("0");
			}
		}
	}
}