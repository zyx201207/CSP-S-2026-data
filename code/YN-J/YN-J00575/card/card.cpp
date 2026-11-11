#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500011], b[500011], c[300011];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (m == 1) {
		cout << n;
		return 0;
	}
	int n1 = n, n2 = n;
	while (n1--) {
		for (int i = 0; i < n; i++)
			b[i] = a[i];
		//a为原始数据，b为复制数据
		bool flag = 0;
		int l = n2;
		for (int i = n1; i < n; i++) {
			int p = a[i];
			for (int j = 0; j < n; j++) {
				if (a[j] == p) {
					l = j;
					flag = 1;
				}
				if (flag) {
					b[j] = -1;
				}
			}
			if (!flag) {
				b[l] = p;
				n2++;
			} else {
				b[l] = p;
				n2 = l + 1;
			}
			for (int j = 0; j < n; j++) {
				if (b[j] != -1)
					c[b[j]]++;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << c[i] << " ";
	}
	return 0;
}