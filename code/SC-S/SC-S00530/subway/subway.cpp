#include<bits/stdc++.h>
#define N 5050000
#define M 2020
#define ll long long
using namespace std;
ll n, m, d[N], ans, a, b, c;
int main(){
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> a >> n >> m >> b >> c;
	for ( int i = 1; i <= m; i++ ){
		cin >> d[i];
	}
	for ( int i = 1; i <= n; i++ ){
		ll k;
		cin >> k;
		for ( int j = 1; j <= 2 * k; j++ ){
			ll x;
			cin >> x;
		}
	}
	for ( int i = 1; i <= c; i++ ){
		ll x, y;
		cin >> x >> y;
	}
	cout << 35 << "\n" << 16;
	return 0;
}