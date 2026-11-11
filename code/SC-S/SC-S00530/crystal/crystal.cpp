#include<bits/stdc++.h>
#define N 5050000
#define M 2020
#define ll long long
using namespace std;
ll n, m, a[N], ans;
int main(){
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for ( int i = 1; i <= n; i++ ){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for ( int i = n; i >= 1; i-- ){
		ll x = m, k = i, sum = 1;
		while ( k >= 1 ){
			k--;
			x -= a[i] - a[k];
			if ( x < 0 ){
				break;
			}else{
				sum++;
			}
		}
		ans = max ( ans, sum );
	}
	cout << ans;
	return 0;
}