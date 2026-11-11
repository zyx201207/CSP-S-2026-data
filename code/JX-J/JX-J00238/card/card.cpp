#include <bits/stdc++.h>
using namespace std;
constexpr int N(5e5 + 9);
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[N]{};
	cin >> n >> m;
	for (int i{}; i < n; ++i) cin >> a[i];
	int ans_num[N]{};
	int num[N]{};
	int now[N]{};
	int end_{};
	for (int i{}; i < n; ++i) {
		for (int j(i); j < n; ++j) {
			if (num[a[j]] == 0) {
				++num[a[j]];
				now[end_++] = a[j];
			} else {
				while (--num[now[--end_]], num[a[j]]);
				++num[a[j]];
				now[end_++] = a[j];
			}
		}
		for (int j{}; j < m; ++j) ans_num[j] += !!num[j]; 
	} 
	for (int i{}; i < m; ++i) cout << ans_num[i] << ' ';
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

