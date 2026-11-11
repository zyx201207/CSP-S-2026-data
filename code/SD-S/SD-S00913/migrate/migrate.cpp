#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;
long long a[N + 5];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		long long n, d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		long long c1 = a[1];
		for(int i = 1;i <= n;i++){
			a[i] = a[i] - c1;
		}
		bool kl = 0;
		for(int i = 2;i <= n;i++){
			if(a[i] - a[i - 1] != a[2] - a[1]) kl = 1;
//			cout << a[i] - a[i - 1] << " " << a[2] - a[1] << endl;
		}
		long long ans = 0;
		if(kl == 0){
			long long c = a[2] - a[1];
			long long cd = (d / c + 1) * 2 - 1;
			ans = n - cd + 2;
//			cout << "c: " << c << " " << cd << " " << ans << endl;
			if(d / c <= 1) ans = 0;
			ans = max(0ll, ans);
		}else ans = 0;
		cout << ans << endl;
	}
	return 0;
}
