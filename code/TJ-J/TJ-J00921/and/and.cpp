#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
typedef long long ll;
ll a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	ll maxn = -1e9;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		maxn = max(a[i], maxn);
	}
	if(m == 1){
		cout << maxn << '\n';
		return 0;
	}
	if(m == n){
		ll last = a[0];
		for(int i = 1; i < n; i++){
			last = last&a[i];
		}
		cout << last << '\n';
		return 0;
	}
	ll ans = -1e9;
	for(ll mask = 0; mask < (1<<n); mask++){
		vector<int> b;
		for(int i = 0; i < n; i++){
			if(mask&(1<<i)){
				b.push_back(i);
			}
		}
		if((int)b.size() != m)continue;
		int u1 = b[0];
		ll last = a[u1];
		for(int i = 1; i < (int)b.size(); i++){
			int u = b[i];
			last = last&a[u];
		}
		ans = max(ans, last);
	}
	cout << ans << '\n';
	return 0;
}
