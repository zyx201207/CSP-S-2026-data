#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 5e5 + 10;

int n,m;
int a[N],s[N];

void solve(){
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1 ; i <= n ; i++) s[i] = s[i - 1] + a[i];
	int ans = 1;
	for (int i = 1 ; i <= n ; i++){
		int L = 1,R = i,res = i;
		while (L <= R){
			int mid = (L + R) >> 1;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) res = mid,R = mid - 1;
			else L = mid + 1;
		}
		ans = max(ans,i - res + 1);
	}	
	cout << ans << endl;
}
signed main(){
	//freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}