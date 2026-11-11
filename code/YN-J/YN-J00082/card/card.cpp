#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500050];
int cnt[300030];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int ju = 1; ju <= n; ju++) {
		int take[n + 1] = {0}; //take[i]=j:拿走a[i]到a[j]的所有卡片，为0则不拿
		int cards[m + 1] = {0}; //cards[i]=j:点数i在a中的下标是j，为0则代表还未出现过
		for (int i = ju; i <= n; i++) {
			if (cards[a[i]] == 0) {
				cards[a[i]] = i;
//				cout << "#put:" << a[i] << "\n";
			} else {
				take[cards[a[i]]] = i - 1;
//				cout << "#take:from" << cards[a[i]] << "to" << i - 1 << "\n";
				cards[a[i]] = i;
			}
		}
		for (int i = ju; i <= n; i++) {
			if (take[i] == 0) {
				cnt[a[i]]++;
			} else {
				i = take[i];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}