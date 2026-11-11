#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 5000;
long long x[2000010];
int tong[N + 5];
pair<int, long long> dp[N + 5]; //dis,way
long long d;
int c, T, n;

void init() {

}

void minus1(int pos) {
	tong[dp[pos].first] -= dp[pos].second;
}

void solve() {
	int cnt;
	long long ans = 0;
	for (int start = 1; start < n; start++) {
		int pre = start, pos = start + 1;
		cnt = 1;
		memset(tong, 0, sizeof(tong));
		dp[start] = {0, 1ll};
		tong[0]++;
		while (pos <= n && x[pos] - x[start] <= d) {
			dp[pos] = {1, 1ll};
			tong[1]++;
			pos++;
		}
		if (pos > n) {
			continue;
		}
		pos--;
		if (pos == start) {
			continue;
		}
		while (pos < n) {
			pos++;
			while (x[pos] - x[pre] > d && pre < pos) {
				minus1(pre);
				pre++;
			}
			if (pre == pos) {
				break;
			}
			while (cnt <= N && tong[cnt] == 0) {
				cnt++;
			}
			if (cnt > N) {
				break;
			}
			if (tong[cnt] == 2) {
				ans++;
			}
			dp[pos] = {cnt + 1, tong[cnt]};
			tong[cnt + 1] += tong[cnt];
			//cout << pos << " " << cnt << endl;
		}
		//cout << start << " " << ans << endl;
		//return;
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) {
		init();
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}