#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void migrate(){
	int n;
	ll d;
	cin >> n >> d;
	ll dt = 2*d-1;
	vector<ll> x(n, 0);
	for (ll i=1; i<=n; i++) cin >> x[i];
	ll ans = 0;
	for (int i=1; i<=n; i++){
		for (int j=i+1; j<=n; j++){
			if (j-i == 3 && x[j]-x[i] == dt && x[j-1]-x[i+1] == 1) ans++;
			else continue;
		}
	}
	cout << ans;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	for (int i=0; i<t; i++) migrate();
	return 0;
}
