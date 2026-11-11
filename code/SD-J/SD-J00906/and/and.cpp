#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n;
int m;
int ans = -1e18;
int a[N];
int b[31];
int s2[N];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	s2[0] = 1;
	for(int i = 1; i <= 30; i ++){
		s2[i] = s2[i - 1] * 2;
	}
	if(n <= 20){
		for(int i = 0; i < (1 << n); i ++){
			int cnt = 0;
			int res = -1;
			for(int j = 0; j < n; j ++){
				if((i >> j) & 1){
					cnt++;
					if(res == -1){
						res = a[j];
					}else{
						res &= a[j];
					}
				}
			}
			if(cnt == m){
				ans = max(ans, res);
			}
		}
		cout << ans;
	}else if(n <= 2000){
		if(m == 1){
			for(int i = 1; i <= n; i ++){
				ans = max(ans, a[i]);
			}
			cout << ans;
		}else if(m == 2){
			for(int i = 1; i <= n; i ++){
				for(int j = i + 1; j <= n; j ++){
					ans = max(ans, a[i] & a[j]);
				}
			}
			cout << ans;
		}else{
			int ans = a[1];
			for(int i = 2; i <= n; i ++){
				ans &= a[i];
			}
			cout << ans;
		}
	}else{
		sort(a + 1, a + n + 1, greater<int>());
		int cnt = a[m - 1];
		cout << cnt;
	}
	return 0;
} 

