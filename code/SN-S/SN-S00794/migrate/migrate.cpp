#include<bits/stdc++.h>
#difine pii pair<int , int>
using namespace std;
const int N = 2e6 + 10;
int n , c , t , d , u , v , w , a[N];

int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	vector<int , pii> g[N];
	cin >> c >> t;
	while(t--) {
		f = 0;
		for(int i = 1;i <= n;i++) {
			a[i] = 0;
		}
		cin >> n >> d;
		cin >> a[1] >> a[2];
		int p = a[2] - a[1];
		for(int i = 3;i <= n;i++) {
			cin >> a[i];
			if(a[i] - a[i - 1] != p) f = 1;
		}
		if(f == 0) {
			if(p / d < 2) cout << 0 << '\n';
			else cout << n - 2 << '\n'; 
		}
	}
	return 0;
}

