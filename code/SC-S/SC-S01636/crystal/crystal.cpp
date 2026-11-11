#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll n,m,s[500005],a[5000005],res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;++i){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;++i) s[i] = s[i - 1] + a[i];
	for (int i = 1;i <= n;++i){
		ll l = 1,r = i,ans = i;
		while (l <= r){
			int mid = l + r >> 1;
			if ((i - mid) * a[i] - s[i - 1] + s[mid - 1] <= m){
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		res = max(res,i - ans + 1);
	}
	cout << res;
	return 0;
}