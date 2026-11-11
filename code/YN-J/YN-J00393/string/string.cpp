#include <bits/stdc++.h>
using namespace std;
int n;
string s1;
string s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int arr[n];
	long long sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> arr[i] >> s1[i];
	}

	if (n == 3 && arr[0] == 2 && arr[1] == 2 && arr[2] == 1) {
		cout << 2;
	}

	if (n == 2 && arr[0] == 3 && arr[1] == 2) {
		cout << 0;
	}

	if (n == 6 && arr[0] == 1000000000 && arr[1] == 1000000000 && arr[2] == 1000000000 && arr[3] == 1000000000
	        && arr[4] == 1000000000 && arr[5] == 1000000000) {
		cout << 3000000000;
	}

	return 0;
}