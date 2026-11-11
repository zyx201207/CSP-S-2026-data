#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200010], h, ans;
int check(int x, int pos){
	string s;
	for(int i = 0; i <= 40; i++) if(s[i] == '1') s[i] = '0';
	int l = 0;
	while(x > 0){
		if(x % 2LL == 1LL) s[++l] = '1';
		else s[++l] = '0';
		x /= 2LL;
	}
	if(s[pos] == '1') return 1;
	return 0;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.in", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int k = 30; k >= 1; k--){
		int sum = 0;
		for(int i = 1; i <= n; i++){
			if(check(a[i], k)) sum++;
		}
		if(sum >= m){
			h = k;
			break;
		}
	}
	if(h == 0){
		cout << 0;
		return 0;
	}
	ans = 1;
	for(int i = 1; i <= n; i++){
		if(check(a[i], h) == 0) a[i] = 0;
	}
	for(int k = h - 1; k >= 1; k--){
		int sum = 0;
		for(int i = 1; i <= n; i++){
			if(check(a[i], k)) sum++;
		}
		if(sum >= m){
			ans = ans * 2 + 1;
			for(int i = 1; i <= n; i++){
				if(check(a[i], k) == 0) a[i] = 0;
			}
		}
		else ans *= 2;
	}
	cout << ans;
	return 0;
}

