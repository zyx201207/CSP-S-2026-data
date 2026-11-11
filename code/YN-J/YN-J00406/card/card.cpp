#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
struct node {
	int x, id;
};
node t[3005];
int cnt[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++) {
		memset(t, 0, sizeof t);
		int idn = 0;
		for (int i = k; i <= n; i++) {
			if (t[a[i]].x == 1) {
				int tmp = t[a[i]].id;
				idn = tmp;
				for (int j = 1; j <= m; j++) {
					if (t[j].id >= tmp) {
						t[j].x = 0;
						t[j].id = 0;
					}
				}
			}
			t[a[i]].x = 1;
			t[a[i]].id = ++idn;
			//cout << idn << ' ';
		}
		//cout << endl;
		for (int i = 1; i <= m; i++) {
			if (t[i].x == 1) {
				cnt[i]++;
			}
		}

	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}