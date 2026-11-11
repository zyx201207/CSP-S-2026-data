#include<bits/stdc++.h>
using namespace std;

#define N 307
#define inf 0x7f7f7f7f
#define inF 0x7f7f7f7f7f7f7f7f
#define ll long long
#define ull unsinge ll
#define ls (i << 1)
#define rs (i << 1 | 1)

int n, d;
int x[2000007];
int f[N][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		for(int i = 1;i <= n;i ++) {
			cin >> x[i];
		}
		if(n > 307) {
			cout << 0 << "\n";
			continue;
		} 
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++) {
			f[i][i][0] = 1;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				for(int k = 1; k <= j; k++) {
					for(int r = n; r >= 1; r--) {
						if(x[j] - x[r] > d) break;
						f[i][j][k] += f[i][r][k - 1];
					}
				}
			} 
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				for(int k = 1; k <= j - i + 1; k++) {
					if(f[i][j][k]) {
						cnt += (f[i][j][k] == 2);
						break;
					}
				}
			} 
		}
		cout << cnt << "\n";
	}
	
	return 0; 
} 
