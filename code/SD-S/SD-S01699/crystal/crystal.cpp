#include <bits/stdc++.h>
using namespace std;
//Oct31==Dec25?
#define ll long long
const int N = 5e5 + 10;
ll a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m, mid;
	ll sum = 0;
	ll ans = 0;
	cin >> n >> m;
	for(ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++){
		if(sum + a[i] + m ==  i * a[i + 1]){
			ans = i + 1;
		}
		sum += a[i];
	}
	for(ll i = ans + 1; i <= n; i++){
		if(a[i] == a[ans])
			ans++;
		if(a[i] != a[ans])
			break;
	}
	cout << ans << endl;
	return 0;
}
