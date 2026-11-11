#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , m , a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a+1,a+n+1,greater<int>());
	for (int mask = 30 ; mask >= 0 ; mask--){
		sort(a+1,a+n+1,greater<int>());
		if (a[m]>>mask){
			int ans = a[1];
			for (int i = 2 ; i <= m ; i++) ans &= a[i];
			cout << ans;
			return 0;
		}
		for (int i = 1 ; i <= n && (a[i]>>mask) ; i++) a[i] -= (1<<mask);
	}
	return 0;
}
