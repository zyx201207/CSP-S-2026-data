#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long ll;
ll a[N], pre[N];
int n, d, c, t;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrater.out", "w", stdout);
	cin >> c >> t;
	while(t--){
	cin >> n >> d;
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n - 1; i++) pre[i] = a[i] - a[i - 1];
	bool ok = true;
	for(int i = 1; i <= n - 1; i++) if(pre[i] != 1)  ok = false;
	if(ok){
		if(n % d == 0) cout << n / d  << endl;
		else cout << n / d - 1<< endl;
	}
}
    return 0;
}
