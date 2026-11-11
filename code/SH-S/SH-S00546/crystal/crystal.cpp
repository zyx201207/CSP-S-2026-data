#include <fstream>
#include <algorithm>

using ll = long long;
std::ifstream fin("crystal.in");
std::ofstream fout("crystal.out");
int n;
ll m;
ll a[500005] = {0};
int ans = 0;
bool all_same = 1;
bool same_diff = 1;
ll diff = 0;

int calc(int x) {
	int sum = 0;
	for (int i = 1; i <= x + 1; ++i) {
		sum += i;
		if (sum > x) {
			return i - 1;
		}
	}
	return 0;
}

int main() {
	fin >> n >> m;
	for (int i = 0; i < n; ++i) {
		fin >> a[i];
		if (i > 0 && a[i] != a[i - 1]) {
			all_same = 0;
		}
		if (i > 1 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			same_diff = 0;
		}
	}
	if (all_same) fout << n;
	else if(same_diff) {
		diff = a[1] - a[0];
		ll times = m / diff;
		fout << std::min(n, calc(times) + 1);
	}
	else {
		std::sort(a, a + n);
		for (int i = a[0]; i < a[n - 1]; ++i) {
			int p = std::upper_bound(a, a + n, i) - 1 - a;
			//小于等于i的最后一个的下标 
			int count = 0;
			ll m_left = m;
			for (int j = p; j >= 0; --j) {
				if (i - a[j] <= m_left) {
					m_left -= i - a[j];
					count++;
				} else {
					break;
				}
			}
			ans = std::max(ans, count);
		}
		fout << ans;
	}
}
