#include<bits/stdc++.h>
#define cs const
#define LL long long
#define pii pair<int, int>
#define fs first
#define sc second

using namespace std;

cs int MAXN = 2e6 + 7;

int c, t, n;
LL d, pos[MAXN], ans;

int mav[MAXN], miv[MAXN];
inline int findAnc(int cur) {
	if (cur ^ mav[cur])
		mav[cur] = findAnc(mav[cur]);
	return mav[cur];
}

inline bool check(int ind) {
	if (pos[ind] - pos[ind - 3] <= d)	return false;
	if (pos[ind] - pos[ind - 2] > d)	return false;
	if (pos[ind - 1] - pos[ind - 3] > d)	return false;
	return true;
}

int main() {
#ifndef DEBUG
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	cin >> c >> t;
	while (t--) {
		cin >> n >> d, ans = 0;
		for (int i = 1; i <= n; ++i)	cin >> pos[i];
		for (int i = 1; i <= n; ++i) {
			mav[i] = i, miv[i] = i;
			if (i >= 2 && pos[i] - pos[i - 1] <= d)
				miv[i] = miv[findAnc(i - 1)], mav[findAnc(i - 1)] = i;
		}
		for (int i = 1; i <= n; i = findAnc(i) + 1) {
			int ll = miv[findAnc(i)], rr = mav[findAnc(i)];
			for (int j = ll; j <= rr; ++j)
				for (int k = ll; pos[j] - pos[k] > d; ++k) {
					int st = k, ed = j;
					while (pos[ed] - pos[k] > d)	ed--;
					while (pos[j] - pos[st] > d)	st++;
					if (abs(ed - st) == 1)	ans++;
				}
		}
		cout << ans << '\n';
	}
	return 0;
}