#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

ifstream fin("crystal.in");
ofstream fout("crystal.out");

const int kN = 5e5 + 1;

int n, ans;
ll s, m, a[kN];

int main() {
	fin.tie(0)->sync_with_stdio(0);
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1; i <= n; i++) {
		s += 1ll * (i - j) * (a[i] - a[i - 1]);
		if (s <= m)
			ans = max(ans, i - j + 1);
		for (; s > m; j++)
			s -= a[i] - a[j];
	}
	fout << ans;
	return 0;
}