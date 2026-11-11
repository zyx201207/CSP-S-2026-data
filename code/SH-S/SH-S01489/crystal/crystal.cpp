#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>

using szt = unsigned long long int;
using ll = long long;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ll n, m;
	scanf("%lld%lld", &n, &m);
	
	std::vector<ll> arr(n);
	
	for(auto& v : arr) {
		scanf("%lld", &v);
	}
	
	std::sort(arr.begin(), arr.end());
	
	std::vector<ll> arrq(n + 1);
	for(int i = 1; i <= n; i++) {
		arrq[i] = arrq[i - 1] + arr[i - 1];
	}
	ll ans = 1;
	for(ll i = 2; i <= n; i++) {
		if((i - 1) * arr[i - 1] - arrq[i - 1] > m) {
			if(arr[i - 1] - arr[i - 2] > m) continue;
			ll l = 1, r = i - 1;
			while(l < r) {
				auto mid = l + r >> 1;
				if((i - mid) * arr[i - 1] - arrq[i - 1] + arrq[mid - 1] > m) {
					l = mid + 1;
				}
				else {
					r = mid;
				}
			}
			ans = std::max(ans, i - l + 1);
			continue;
		}
		ans = std::max(ans, i);
	}
	printf("%lld", ans);
	return 0;
}
