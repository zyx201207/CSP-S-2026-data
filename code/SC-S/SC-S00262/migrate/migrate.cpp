#include<bits/stdc++.h>
using namespace std;
long long c,t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--) {
		long long n, m;
		cin >> n >> m;
		long long a0,a1,an;
		if(n>=2) cin>>a0>>a1;
		n-=2;
		for (long long i = 0; i < n; i++) cin>>an;
		long long te=a1 - a0;
		if ( te<m&&te>30/100) cout << n / 2;
		else cout << 0;
		cout << '\n';
	}

	return 0;
}