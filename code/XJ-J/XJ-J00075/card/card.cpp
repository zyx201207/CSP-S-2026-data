#include <bits/stdc++.h>
using namespace std;

int a[2000];
int b[2000];
int ans[2000];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			bool flag = false;
			for (int j = 0; j < n; j++) {
				if (b[j] == a[i]) {
					flag = true;
				}
			}
			if (flag == true) {
				for (int j = 0; j < cnt; j++) {
					b[j] = 0;
				}
				cnt = 0;
				b[cnt] = a[i];
			} else {
				b[cnt] = a[i];
				cnt++;
			}
		}
		for (int j = 0; j < cnt; j++) {
			ans[b[j]]++;
			b[j] = 0;
		}
		cnt = 0;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
} 
