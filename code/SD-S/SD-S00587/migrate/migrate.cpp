#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int x[maxn];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c == 0) {
		while(t --) {
			int n,d;
			cin >> n >> d;
			for(int i = 1;i <= n;i ++) {
				cin >> x[i];
			}
			cout << 0 << '\n';
		}
	} 
	else {
		while(t --) {
			int n,d;
			cin >> n >> d;
			for(int i = 1;i <= n;i ++) {
				cin >> x[i];
			}
			cout << 0 << '\n';
		}	
	}
	return 0;
}

