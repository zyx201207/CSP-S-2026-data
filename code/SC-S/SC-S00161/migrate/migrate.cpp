#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 321;
int c, t;
int s[N];
int f[N][N][N];
int len[N][N];
void clear() {
	for (int i = 1; i <= 320; i++) {
		for (int j = 1; j <= 320; j++) {
			for (int k = 1; k <= 320; k++) {
				f[i][j][k] = 0;
				s[i] = 0;
				len[i][j] = 0;
			}

		}
	}
}
void solve() {
	clear();
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	if (c == 11 || c == 12) {
		if(s[2]-s[1]<=d)cout<<n-3<<"\n";
		else cout<<0<<"\n";
		return ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int sum = 0,  lenn = 0;
			for (int k = i + 1; k <= j; k++) {
				sum += s[k] - s[k - 1];
				if (sum > d) {
					lenn++;
					sum = s[k] - s[k - 1];
				}
			}
			if (sum > 0)lenn++;
			len[i][j] = lenn;
			//	cout<<i<<" "<<j<<" "<<lenn<<"\n";
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			//	if(s[j]-s[i]>d)break;
			if (len[i][j] == 1) {
				f[i][j][1] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = i + 1; k < j; k++) {
				if (len[k][j] == 1) {
					for (int z = 1; z <= len[i][j]; z++) {
						f[i][j][z] += f[i][k][z - 1];
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			//		cout<<f[i][j][len[i][j]]<<"\n";
			if (f[i][j][len[i][j]] == 2)ans++;
		}
	}
	//cout<<f[1][4][2]<<" "<<f[2][5][2];
	cout << ans << "\n";
	return ;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t--) {
		solve();
	}
	return 0;
}