#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , a[200005] , ans , pre[200005] , suf[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	int sum = 0;
	for (int i = 1 ; i <= n ; i++) cin >> a[i] >> c[i] , sum += a[i];
	for (int i = 1 ; i <= n ; i++) pre[i] = pre[i-1] + a[i];
	for (int i = n ; i >= 1 ; i--) suf[i] = suf[i+1] + a[i];
	int i = 1 , j = 1 , pi = 0 , pj = 0;
	while (1){
		if (pi+pj-1 >= sum) break;
		int k = min({pre[i],suf[n-j+1],(sum+1)/2});
		if (k == pre[i]) ans += (pre[i]-pi) * (c[i] != c[n-j+1]) , i++;
		else if (k == suf[n-j+1]) ans += (suf[n-j+1]-pj) * (c[i] != c[n-j+1]) , j++;
		pi = pj = k;
	}
	cout << ans;
	return 0;
}
