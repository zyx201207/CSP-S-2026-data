#include <bits/stdc++.h>
using namespace std;

long long t, n, k, m, a[1000005], cnt[1000005], c[1000005];
queue <long long> q;

int main() {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) q.push (a[j]);
//		cout << q.front () << "     -----\n";
		long long h = 0;
		for (int j = i; j <= n; j++) {
//			h++;
			if (cnt[q.front ()] != 0) {
				h -= h - cnt[q.front ()] - 1;
				h++;
				q.pop ();
			}
			else {
				cnt[q.front ()] = h;
				h++;
				q.pop ();
			}
//			cout << h << " " << q.front () << "\n";
		}
		for (int j = 1; j <= m; j++) {
			if (cnt[j] != 0) c[j]++;
			cnt[j] = 0;
		}
		while (!q.empty ()) q.pop ();
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	cout << "\n";
	return 0;
}
