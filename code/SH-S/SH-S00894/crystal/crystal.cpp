#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("crystal.in");
ofstream fout("crystal.out");
using i64 = long long;
constexpr int MAXN = 5e5 + 5;
int n, ans;
i64 m, a[MAXN], pre[MAXN];
bool check(int id, int pos) {
	i64 tot = pre[pos - 1] - pre[id - 1];
	i64 goal = i64(pos - id) * a[pos];
	if (goal - tot <= m) return 1;
	return 0;
}
int main() {
	fin >> n >> m;
	for (int i = 1; i <= n; ++i) fin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i;
		while (l < r) {
			int mid = l + ((r - l) >> 1);
			if (check(mid, i)) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	fout << ans << '\n';
	return 0;
}
