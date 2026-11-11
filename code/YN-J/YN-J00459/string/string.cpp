#include <bits/stdc++.h>
using namespace std;
vector<string> z;

int main() {
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);
	int n;
	cin >> n;
	int a;
	string c;
	string zf;
	if (n == 1) {
		cout << "0";
	}
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		zf += c;
		z[i] = zf;
	}
	long long x;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (z[i] != z[j]) {
				x++;
			}
		}
	}
	cout << x;





	return 0;
}