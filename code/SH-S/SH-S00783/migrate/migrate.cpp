#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 1;
ll c, t, n, d, x[N];
void init(){
	n = d = 0;
	memset(x, 0, sizeof(x));
}
bool A(){
	for (ll i = 2;i < n;i++){
		if (x[i + 1] - x[i] != x[2] - x[1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (ll tt = 1;tt <= t;tt++){
		init();
		cin >> n >> d;
		for (ll i = 1;i <= n;i++){
			cin >> x[i];
		}
		if (A()){
			d /= x[2] - x[1];
			if (d >= 2){
				cout << max(0ll, n + 1 - 2 * d) << "\n";
			}else{
				cout << "0\n";
			}
			continue;
		}
	}
	return 0;
}
