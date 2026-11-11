#include<bits/stdc++.h>
using namespace std;

bool MST;
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define N 500010
int n, m;
int a[N];
int p[N], top;
int sum[N];
void solve_() {
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
	}
	rep(vis, 1, n) {
		top = 0;
		rep(i, vis, n) {
			per(j, top, 1) {
				if (a[i] == p[j]) {
					top = j - 1;
					break;
				}
			}
			p[++top] = a[i];
		}
		rep(i, 1, top) {
			sum[p[i]]++;
		}
	}
	rep(i, 1, m) {
		cout << sum[i] << " \n"[i == m];
	}
}
bool MED;
signed main() {
//	cerr << abs(&MST - &MED) / 1024 / 1024 << "MB\n";
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) {
		solve_();
	}
	return 0;
}
