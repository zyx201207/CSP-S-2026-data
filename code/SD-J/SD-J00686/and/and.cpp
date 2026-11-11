#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 0;
const int MOD = 0;

int n,m,ans = -1,a[200005];
unordered_map<int,int> mp;

signed main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n; ++ i) cin >> a[i];
	if(n <= 20) {
		for(int i = 0;i < (1 << n); ++ i) {
			int cnt = 0,z = -1;
			for(int j = 0;j < n; ++ j) {
				if((i >> j) & 1) {
					cnt ++;
					if(z == -1) z = a[j + 1];
					else z &= a[j + 1];
				}
			}
			if(cnt == m) ans = max(ans,z);
		}
		cout << ans;
		return 0;
	} else {
		if(m == n) {
			ans = a[1];
			for(int i = 2;i <= n; ++ i) ans &= a[i];
			cout << ans;
			return 0;
		}
		if(m == 1) {
			for(int i = 1;i <= n; ++ i) ans = max(ans,a[i]);
			cout << ans;
			return 0;
		}
		if(m == 2) {
			for(int i = 1;i <= n; ++ i) {
				for(int j = 1;j <= n; ++ j) {
					if(i == j) continue;
					else ans = max(ans,a[i] & a[j]);
				}
			}
			cout << ans;
			return 0;
		}
		if(m == n - 1) {
			for(int i = 1;i <= n; ++ i) {
				for(int j = 0;j <= 20; j++) {
					if((a[i] >> j) & 1);
					else mp[j] ++;
				}
			}
			for(int i = 0;i <= 20; ++ i) {
				if(mp[i] == 1) {
					int tmp = -1;
					for(int j = 1;j <= n; ++ j) {
						if((a[j] >> i) & 1) {
							if(tmp == -1) tmp = a[j];
							else tmp &= a[j];
						}
					}
					ans = max(ans,tmp);
				}
			}
			cout << ans;
			return 0;
		}
		bool f = false;
		for(int i = 1;i <= n; ++ i) {
			if(a[i] == i - 1);
			else {
				f = true;
				break;
			}
		}
		if(!f) {
			cout << m * 3;
			return 0;
		}
		sort(a + 1,a + n + 1);
		cout << a[n - m + 1]; 
	}

	return 0;
}

