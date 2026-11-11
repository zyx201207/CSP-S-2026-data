#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 3;
int n;
#define ll long long
ll a[MAXN];
char c[MAXN];
bool ok(string s){
	bool f = 1;
	for (int i = 0; i < s.size(); i++){
		if (s[i] != s[s.size() - 1 - i]){
			f = 0;
		}
	}
	return f;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	string s = "";
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}
	if (ok(s)){
		cout << 0;
		return 0;
	}
	ll ans = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] != s[s.size() - 1 - i]){
			ans++;
		}
	}
	cout << ans / 2;
	return 0;
}
