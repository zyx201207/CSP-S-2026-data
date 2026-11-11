#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[200005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << n << " " << m;
	return 0;
}

