#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 1;

int n, c;
ll a[N], d;///8

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T;
	cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		cin >> a[1];
		if(n==1){
			cout << "0\n";
			continue;
		}
		bool A =1;
		cin >> a[2];
		ll h=a[2]-a[1];
		for(int i = 3; i <= n; i++) {
			cin >> a[i];
			if(a[i]-a[i-1] != h) A =0;
		}
		if(A) {
			if(h>=d or d<2*h) cout<<"0\n";
			else cout <<max(n-abs(2*(d/h))+1,0ll) << '\n';
			continue;
		}
		
	}
	return 0;
}

