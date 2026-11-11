#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int maxn = 2e6 + 5;
i64 c, t, n;
i64 d, a[maxn];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t-- > 0){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		//arithmetic
		i64 commond = a[2] - a[1];
		i64 cnt = d / commond;
		cout << n << " " << commond << " " << d << " " << cnt << endl;
		i64 tmp = n - 1;
		cnt = min(cnt, tmp);
		i64 ans = 0;
		if(cnt >= 2){
			for(i64 i = 1; i <= n - cnt; i++){
				ans += n - (i + cnt);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
