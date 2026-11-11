#include <bits/stdc++.h>

using namespace std;

int n , m;
long long a[200005] , ma;
long long ans = 0 , jsq;
int s[100];
void dfs(int i , int s1) {
	if(i == n) {
		if(s1 == m) {
			jsq = 0;
			bool f = true;
			for(int i = 1 ; i <= n ; i++) {
				if(s[i] == 1) {
					if(f) {
						jsq = a[i];f = false;
					}else jsq = jsq & a[i];
				}
			}
			ans = max(ans , jsq);
		}return;
	}
	i++;
	s[i] = 0;
	dfs(i , s1);
	s[i] = 1;
	dfs(i , s1 + 1);
}
int main() {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		scanf("%lld" , &a[i]);
		ma = max(ma , a[i]);
	}
	if(m == 1) {
		for(int i = 1 ; i <= n ; i++) if(a[i] > ans) ans = a[i];
		cout << ans;
		return 0;
	}
	else if(m == n) {
		ans = a[1];
		for(int i = 2 ; i <= n ; i++) ans = ans & a[i];
		cout << ans;
		return 0;
	}
	else if(m == 2) {
		for(int i = 1 ; i <= n ; i++) {
			for(int j = i + 1 ; j <= n ; j++) {
				ans = max(ans , a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	else if(n <= 20) {
		dfs(0 , 0);
		cout << ans;
		return 0;
	}
	else if(ma < 4) {
		long long s3 , s2 , s1;
		for(int i = 1 ; i <= n ; i++) {
			if(a[i] == 3) s3++;
			if(a[i] >= 2) s2++;
			if(a[i]) s1++;
		}
		if(s3 >= m) cout << 3;
		else if(s2 >= m) cout << 2;
		else if(s1 >= m) cout << 1;
		else cout << 0;
		return 0;
	}
	else {
		sort(a + 1 , a + n + 1);
		reverse(a + 1 , a + n + 1);
		ans = a[1];
		for(int i = 2 ; i <= m ; i++) ans = ans & a[i];
		cout << ans;
	}
	return 0;
} 
