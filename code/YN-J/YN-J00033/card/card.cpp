#include<bits/stdc++.h>
using namespace std;
int n, m, a[500001], b[500001];

//void panduan(int i, int y) {
//	for (int j = 1; j < i; j++) {
//		if (b[j] == b[y]) {
//			for (int k = j + 1; k <= y; k++) {
//				b[k] = 0;
//				y--;
//			}
//		}
//	}
//	return;
//}


int main() {
	freopen("card.in", "w", stdin);
	freopen("card.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	for (int o = 1; o <= m; o++) {
//		int sum = 0;
//		b[1] = a[1];
//		int y = 2;
//		for (int i = 2; i <= n; i++) {
//			b[y] = a[i];
//			panduan(i, y);
//		}
//		int j = 1;
//		while (a[j] != 0) {
//			j++;
//		}
///		j -= 1;
//		for (int i = 1; i <= j; i++) {
//			if (b[i] == o) {
//				sum++;
//			}
//		}
//		cout << sum << " ";
//	}
	for (int i = 1; i <= n; i++) {
		b[a[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i];
	}
}