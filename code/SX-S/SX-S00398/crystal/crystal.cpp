#include <bits/stdc++.h>//75分
using namespace std;
#define int long long
#define N 200010
int n, m;
int f[N];
int a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int m1 = m;
	int ji = 0;
	int jia[N];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		jia[i] = 1;
		if (a[i] == i)
			ji++;
		if (i > 1)
			f[i] = a[i] - a[i - 1];
	}
	//特殊性质A
	int shu = 1;
	if (ji == n) {
		while (1) {
			m -= shu;
			shu++;
			if (m < 0)
				break;
			else
				jia[n]++;
		}
	}
	//特殊性质B
	shu = f[n];
	if (f[n] <= 0) {
		shu = -shu;
	}
	int q = 0;
	for (int i = 3; i <= n; ++i) {
		if (f[i] == f[i - 1])
			q++;
	}
	if (q == n - 2) {
		while (1) {
			m -= shu;
			shu *= 2;
			if (m < 0)
				break;
			else
				jia[n]++;
		}
	}
	//通解
	sort(a + 1, a + n + 1);
	int p;
	for (int i = n; i >= 2; --i) {
		for (int j = i - 1; j >= 1; --j) {
			p = a[i] - a[j];
			if (m < p)
				break;
			else {
				jia[i]++;
				m -= p;
			}
		}
		m = m1;
	}
	sort(jia + 1, jia + n + 1);
	cout << jia[n] << '\n';
	return 0;
}
/*
欲寄彩筏兼尺素
山长水阔知何处
*/