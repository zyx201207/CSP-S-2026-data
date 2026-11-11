#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 10;
int n,m,ans,a[MAXN],s[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;++i) s[i] = s[i - 1] + a[i];
	int p = 1;
	for(int i = 1;i <= n;++i){
		while(p < i&&(i - p + 1) * a[i] - (s[i] - s[p - 1]) > m) ++p;
		ans = max(ans,i - p + 1);
	}
	cout << ans;
	return 0;
}
/*

5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/
