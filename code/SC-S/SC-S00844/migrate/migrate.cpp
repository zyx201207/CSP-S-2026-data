#include <stdio.h>
#include <cstring>
#define SIZE 50010
#define G 5010
#define INF 0x3f3f3f3f3f3f3f3fll
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
using ll = long long;
int c;
int n;
int k;
ll sub[SIZE];
int inx[SIZE][3];
int N, M;
ll dp[G][G];
int edge[G][G];
ll arr[SIZE];
ll d;
int T;
void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", edge[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%lld", arr + i);
		if (n <= 5000) {
			memset(edge, 0x3f, sizeof(edge));
			for (int l = 1; l <= n; l++) edge[l][l] = 0;

			int tot = 0;
			for (int p = 1; p <= n; p++) {
				for (int i = 1; i < p; i++)
					if (arr[p] - arr[i] <= d)
						edge[i][p] = 1;
			}
			for (int p = 1; p <= n; p++) {
				for (int i = 1; i < p; i++) {
					if (edge[i][p] <= 1) break;
					for (int j = i + 1; j < p; j++)
						edge[i][p] = min(edge[i][p], edge[i][j] + edge[j][p]);

					int cnt = 0;
					for (int j = i + 1; j < p; j++) {
						if (edge[i][p] == edge[i][j] + edge[j][p]) cnt++;
					}
					if (cnt == 2) tot++;
				}
			}
//			print();
			printf("%d\n", tot);
		}

	}
}