#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int NN = 5e5 + 10;
vector<int> box(N + 1, 0);
int  a[NN], n, m, x;
vector<int> ans(N + 1, 0);
vector<int> vis(N + 1, 0);

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		vis.clear();
		box.clear();

		for (int j = i; j <= n; j++) {

			x = a[j];

			if (box[x] != 0) {
				for (int p = box[x]; p <= j - 1; p++) {

					vis[p] = 1;
				}
			}

			box[x] = j;
		}

		for (int j = i; j <= n; j++) {



			if (vis[j] == 0) {
				ans[a[j]]++;
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}


	return 0;
}