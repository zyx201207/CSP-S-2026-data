//#include <bits/stdc++.h>
//using namespace std;
//#define ll long long
//int b[300005], a[500005];
//
//int main() {
////	freopen("card.in", "r", stdin);
////	freopen("card.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int j = n, flag = 1; j >= flag && flag <= n; j--) {
//		if (a[j] == a[flag]) {
//			b[a[j]] += 1;
//			flag++;
//			j = n + 1;
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		cout << b[i] << " ";
//	}
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int b[300005], a[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int flag = i;
		for (int j = n; j >= flag && flag <= n; j--) {
			if (a[j] == a[flag]) {
				b[a[j]]++;
				flag = j + 1;
				j = n + 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	return 0;
}