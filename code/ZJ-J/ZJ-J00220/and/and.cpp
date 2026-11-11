#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> a[N];
int siz[N];
long long num[N];
int maxx;
void getnum(int x, int i) {
	int cnt = 0;
	while(x) {
		a[i].push_back(x & 1);
		siz[cnt++] += (x & 1);
		x >>= 1;
	}
	maxx = max(maxx, int(a[i].size()));
}
int f[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> num[i];
		getnum(num[i], i);
	}
	for(int i = 1; i <= n; i++) {
		while(a[i].size() < maxx) a[i].push_back(0);
	}
	long long ans = 2147483647;
	bool fl = 0;
	for(int i = maxx - 1; i >= 0; i--) {
		if(siz[i] > m) break;
		if(siz[i] == m) {
			for(int j = 1; j <= n; j++) {
				if(a[j][i] == 1) {
					ans &= num[j];
				}
			}
			break;
		}	
	}
	if(ans != 2147483647) cout << ans << '\n';
	else {
		int op = n;
		for(int i = maxx - 1; i >= 0; i--) {
			if(siz[i] >= m) {
				for(int j = 1; j <= n; j++) {
					if(op == m) break;
					if(a[j][i] == 0 && !f[j]) {
						f[j] = 1, op--;
						for(int k = 0; k <= maxx - 1; k++) {
							siz[k] -= a[j][k];
						}
					}
				}
			}
			if(op == m) break;
		}
		for(int i = 1; i <= n; i++) {
			if(!f[i]) ans &= num[i];
		}
		cout << ans << endl;
	}
	return 0;
}
