#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int MAXN = 5e5 + 3;
int n;
ll m;
ll a[MAXN], pre[MAXN];
bool check(int p, int k, ll c){
	if(1ll * p * a[k] >= c + pre[p - 1]) return true;
	return false;
}
int main(){
	IOS
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + a[i];
	}
	int ans = 1;
	for(int k = 1;k <= n;k++){
		ll c = 1ll * k * a[k] - pre[k - 1] - m;
		if(a[k] <= 0){
			if(a[k] >= c){
				ans = max(ans, k);
			}
		} else {
			int l = 1, r = k;
			while(l <= r){
				int mid = (l + r) / 2;
				if(!check(mid, k, c)){
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			ans = max(ans, k - l + 1);
		}
	}
	cout << ans;
	return 0;
}
