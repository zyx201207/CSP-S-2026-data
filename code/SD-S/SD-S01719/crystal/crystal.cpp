#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , m , a[500005] , ans , s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1 ; i <= n ; i++) s[i] = s[i-1] + a[i];
	for (int i = 1 ; i <= n ; i++){
		int l = 1 , r = i , res = i;
		while (l <= r){
			int mid = l+r >> 1;
			if (a[i]*(i-mid)-(s[i-1]-s[mid-1]) <= m) res = mid , r = mid-1;
			else l = mid+1;
		}
		ans = max(ans,i-res+1);
	}
	cout << ans;
	return 0;
}
