#include<bits/stdc++.h>
using namespace std;
#define int long long
#define CLOSE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n, x, ans;
string s;
char a;
signed main() {
	CLOSE
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x >> a;
		while(x--) {
			s += a;
		}
	}
	int len = s.size();
	for(int i = 0; i <= len / 2 - 1; i++) {
		if(s[i] != s[len - i - 1]) {
			ans++;
		} 
	} 
	cout << ans ;
}
