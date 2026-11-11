#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n,m,ans;
ll a[500005],sum[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
		ll l = 0,r = i + 1;
		while(l + 1 < r){
			ll mid = l + r >> 1;
			if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) r = mid;
			else l = mid;
		}
		ans = max(ans,i - r + 1);
	} 
	cout << ans << "\n";
	return 0;
}
