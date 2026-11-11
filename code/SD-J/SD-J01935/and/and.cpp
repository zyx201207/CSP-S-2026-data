#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 2e5 + 5;
ll n, m;
ll a[M];
ll res;
vector<ll> ones[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++ ) cin >> a[i];
	for (ll i = 1; i <= n; i++ ){
		for (ll j = 29; j >= 0; j-- ){
			if (a[i] & (1 << j)) ones[j].push_back(a[i]);
		}
	}
	ll pos = -1;
	for (ll i = 29; i >= 0; i-- ){
		if (ones[i].size() > m){
			pos = i;
			break;
		}
		if (ones[i].size() == m){
			ll ans = ones[i][0];
			for (ll j = 1; j < ones[i].size(); j++ ) ans &= ones[i][j];
			cout << ans << '\n';
			return 0;
		}
	}
	if (pos == -1){
		cout << "0\n";
		return 0;
	}
	res = (1 << pos);
	vector<ll> tmp;
	for (ll val : ones[pos]) tmp.push_back(val);
	for (ll i = pos - 1; i >= 0; i-- ){
		vector<ll> tmp2;
		for (ll val2 : tmp) tmp2.push_back(val2);
		tmp.clear();
		for (ll val3 : tmp2){
			if (val3 & (1 << i)) tmp.push_back(val3);
		}
		if (tmp.size() >= m) res += (1 << i);
		else{
			tmp.clear();
			for (ll val4 : tmp2) tmp.push_back(val4); 
		}
	}
	cout << res << '\n';
	return 0;
} 
