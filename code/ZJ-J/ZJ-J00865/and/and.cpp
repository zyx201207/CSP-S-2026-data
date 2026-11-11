#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], cnt[N][35];
long long pwr[35];
vector<long long> v[35];

void Turn(int x) {
	int res[31] = {0}, j = 0, tmp = a[x];
	while (tmp) {
		res[j++] = tmp % 2;
		tmp /= 2;
	}
	for (j = 0; j <= 30; j++) {
		cnt[x][j] += res[j];
	}
}

int Next(int i) {
	int k;
	for (k = i - 1; k >= 0; k--) {
		for (int j = 0; j < v[i].size(); j++) {
			if (cnt[v[i][j]][k]) {
				v[k].push_back(v[i][j]);
			}
		}
		if (v[k].size() >= m) {
			return k;
		}
	}
	return -1;
}


int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for (long long i = 0, j = 1; i <= 31; i++) {
		pwr[(int)i] = j;
		j *= 2;
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v[31].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		Turn(i);
	long long ans = 0;
	int i = Next(31);
	while (i >= 0) {
		ans += pwr[i];
		i = Next(i);
	}
	cout << ans << endl;
	return 0;
}
