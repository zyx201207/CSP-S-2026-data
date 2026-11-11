#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int a[N];
int n, d;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int pd=a[2]-a[1];
		if(d<2*pd) cout<<0<<"\n";
		else{
			if(d%pd==0){
			int ans=n-(d/pd);
			if(ans<=0) ans=0;
			cout<<ans<<"\n";
			}else{
				int ans=n-(d/pd)-1;
				if(ans<=0) ans=0;
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}