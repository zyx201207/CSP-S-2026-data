#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
vector<int> vl[2000005], vr[2000005];
int pl[2000005], pr[2000005];
long long ansl[2000005], ansr[2000005];
int visl[2000005], visr[2000005];

//void dfsl(int w) {
//	cout << w << endl;
//	visl[w] = 1;
//	ansl[w] += vl[w].size();
//	for (int i = 0; i < vl[w].size(); i++) {
//		if (vl[w][i] >= w) {
//			ansl[w]--;
//			continue;
//		}
//		dfsl(vl[w][i]);
//		if (i == 0)
//			ansl[w] += ansl[vl[w][0]];
//	}
//	return ;
//}
//
//void dfsr(int w) {
//	visr[w] = 1;
//	ansr[w] += vr[w].size();
//	for (int i = 0; i < vr[w].size(); i++) {
//		if (vr[w][i] <= w) {
//			ansr[w]--;
//			continue;
//		}
//		dfsr(vr[w][i]);
//		if (i == 0)
//			ansr[w] += ansr[vr[w][0]];
//	}
//	return ;
//}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n;
		long long d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		//sort(x + 1, x + n + 1);
		int p = 1;
		for (int i = 1; i <= n; i++) {
			vl[i].clear();
			vr[i].clear();
			ansl[i] = ansr[i] = 0;
			visl[i] = visr[i] = 0;
			pl[i] = pr[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			while (p < n && x[i] + d >= x[p + 1]) {
				p++;
			}
			if (p != i)
				vl[p].push_back(i);
			//cout << p << " ";
			pl[i] = p;
		}
		//cout << 0.5 << endl;
//		for (int i = n; i >= 1; i--) {
//			if (visl[i] == 0)
//				dfsl(i);
//		}
		for (int i = 1; i <= n; i++) {
			ansl[i] = vl[i].size();
			if (vl[i].size() > 0)
				ansl[i] += ansl[vl[i][0]];
		}
		//cout << 1 << endl;
		//cout << endl;
		for (int i = n; i >= 1; i--) {
			while (p > 1 && x[i] - d <= x[p - 1]) {
				p--;
			}
			if (p != i)
				vr[p].push_back(i);
			//cout << p << " ";
			pr[i] = p;
		}
		//cout << 1.5 << endl;
//		for (int i = 1; i <= n; i++) {
//			if (visr[i] == 0)
//				dfsr(i);
//		}
		for (int i = n; i >= 1; i--) {
			ansr[i] = vr[i].size();
			if (vr[i].size() > 0)
				ansr[i] += ansr[vr[i][0]];
		}
		//cout << 2 << endl;
		long long ans = 0;
		for (int i = 2; i <= n - 2; i++) {
			if (pr[i + 1] >= i || pl[i] <= i + 1)
				continue;
			ans += (long long)ansl[i + 1] * ansr[i];
		}
		cout << ans << endl;
	}
	return 0;
}
