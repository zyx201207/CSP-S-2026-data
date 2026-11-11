#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int long long m, n;
	cin >> n >> m;
	vector<int long long> s(n);
	for (int k = 0; k < n; k++) {
		cin >> s[n];
	}
	for (int i = 1; i <= n; i++) {
		for (int k = i - 1; k <= n; k++) {
			for (int x = i - 1; x <= n; x++) {
				if (k != s[x])
					break;
				//else {
				//delete (s[x]);
				//inset(s[x]);
				//}
			}
			if (k = s[i]) {
				i = k;
			}
		}
		cout << i	;
	}
	return 0;
}