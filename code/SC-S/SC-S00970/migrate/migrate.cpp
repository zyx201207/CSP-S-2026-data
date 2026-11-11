#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2 * 1e6 + 5;
int x[MAXN];
int c, t;
int n, d;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1;i <= n; ++i) {
			cin >> x[i];
		} 
		int jid = 0;
		for(int i = 1;i <= n; ++i) {
			for(int j = i + 2;j <= n; ++j) {
				int ji = 0;
				for(int k = i;k <= j; ++k) {
					int ml = x[k] - x[i];
					int ml1 = x[j] - x[k];
					if(ml <= d && ml1 <= d) {
						ji++;
					} 
				}
				if(ji == 2) {
					jid++;
				}
			}
		}
		cout << jid << endl;
	}
	return 0;
}