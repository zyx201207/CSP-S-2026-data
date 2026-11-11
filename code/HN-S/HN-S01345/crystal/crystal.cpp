#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m, a[500005];
ll sum[500005], ans[500005];
ll cnt = 0;

bool check(ll k, ll x, ll id, ll y){
	if (sum[id - x] > (k - x) * a[id] + y){
		return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	sum[0] = 0;
	for (int i = 1 ; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
		ans[i] = a[i] * i;
	} 
	for (ll i = 1; i <= n; i++){
		ll op = sum[i] + m;
		if (op >= ans[i]){
			cnt = max(cnt, i);
		} 
		else{
			if (sum[i - (ll)(op / a[i])] > (ll)(op % a[i])){
				ll l = 1, r = op / a[i], tt = 0;
				while (l <= r){
					int mid = (l + r) / 2;
					if (check((ll)(op / a[i]), mid, i, (ll)(op % a[i]))){
						l = mid + 1;
						tt = mid;
					}
					else{
						r = mid - 1;
					}
				}
				cnt = max(cnt, tt);
			}
			else{
				cnt = max(cnt, (ll)(op / a[i]));
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
