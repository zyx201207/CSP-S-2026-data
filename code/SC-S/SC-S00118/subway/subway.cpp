#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int c, n, m, d, q, o, l, e;
const int N = 5e5 + 5;
int k[N], w[N];
int s[1001][1001], t[1001][1001];

int main() {
	freopen("swbway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++) {
		cin >> k[i];
		for(int j = 1; j <= 2 * k[i]; j ++) {
			if(j % 2 == 1) {
				cin >> s[i][++o];
			} else {
				cin >> t[i][++e];
			}
		}
	}
	while(q --) {
		ll sum = 0, spot = 0, line = 0;
		int l, r;
		cin >> l >> r;
		sum += (w[l] + w[r]);
		//cout << w[l] << " " << w[r] << '\n';
		
			for(int i = 1; i <= k[1]; i ++) {
				if(s[1][i] == l) {
					spot = i;
					break;
				}
			}	
		
	//	cout << ";" << spot << ";;;";
		for(int i = spot; i <= k[1]; i ++) {
			if(s[1][i] == r) {
				//cout << ";";
				sum += t[l][l] + t[l][r];
				break;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
