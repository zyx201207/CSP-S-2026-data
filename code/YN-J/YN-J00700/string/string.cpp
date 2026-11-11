#include <bits/stdc++.h>
using namespace std;
char name[1005];
int num[1005];
char m[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, maxx = INT_MIN, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i] >> name[i] ;
		if (num[i] >= maxx) {
			maxx = num[i] ;
		}
	}
	for (int i = 1; i <= n; i++) {
		sum += num[i];
	}
	//cout << sum << "      " << maxx << "        ";
	cout << sum - maxx;
	return 0;
}
