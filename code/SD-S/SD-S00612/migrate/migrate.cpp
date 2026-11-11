#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010;
int c,t,n,d;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--) {
		cin>>n>>d;
		for (int i=1; i<=n; i++) {
			cin>>x[i];
		}
		int maxd=x[2]-x[1];
		int s=d/maxd;
		if (s==1||s==0)cout<<"0\n";
		cout<<n-s*2+1<<"\n";
	}
	return 0;
}
