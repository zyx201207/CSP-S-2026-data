#include <bits/stdc++.h>
using namespace std;
int n, ma;
int arr[500005], brr[300005], crr[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		brr[arr[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		cout << brr[i];
	}
	return 0;
}




















