#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
int solve(string s){
	int ans = 0, sz = s.size();
	for(int i = sz/2-1; i >= 0; i--) if(s[i] != s[sz-1-i]) ans++;
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fast;
	string s = "";
	long long n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		char c; long long x;
		cin >> x >> c;
		while(x--){
			s += c;
		}
	}
	cout << solve(s);
	return 0;
}