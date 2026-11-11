#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	vi a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	int ans = 0;
	for(int x=20; x>=0; x--) {
		int tag = ans | (1 << x), cnt = 0;
		for(int i=0; i<n; i++) {
			if((a[i] & tag) == tag) cnt++;
		}
		if(cnt >= m) ans = tag;
	}
	cout << ans;
	return 0;
}
