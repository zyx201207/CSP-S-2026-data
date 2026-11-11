#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m, num;
ll p[N];
ll sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		sum[i] = sum[i - 1] + p[i];
	}
	sort(p + 1, p + n + 1);

	for (int i = 1; i <= n; i++) {
		num = (i - 1) * p[i] - sum[i - 1];                                             
		if (num > m) {
			cout << i - 1;
			break;                                                                                                                                                                
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

