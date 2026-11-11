#include <bits/stdc++.h>
using namespace std;
int ans[100001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[100001];
	bool number[100001];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int num[100001];
		int next[100001];
		next[0] = i;
		for (int i = 1; i <= m; i++) {
			number[i] = false;
		}
		for (int j = i; j <= n; j++) {
			if (number[a[j]] == false) {
				num[j] = a[j];
				number[a[j]] = true;
				next[j] = j + 1;
			} else {
				int v;
				for (v = next[0]; v < j; v = next[v]) {
					if (a[j] == num[v])
						break;
				}
				next[v - 1] = j;
				num[j] = a[j];
				next[j] = j + 1;
				number[a[j]] = true;
			}
		}
		for (int k = next[0]; k <= n; k = next[k]) {
			ans[num[k]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}