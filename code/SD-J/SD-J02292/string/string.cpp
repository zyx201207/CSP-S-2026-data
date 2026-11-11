#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
int k;
char c;
string str;
int my_mt(string s) {
	ll sl = s.size();
	for(ll i = 0; i * 2 < sl;i++)
		if(s[i] != s[sl - i - 1]) ans++;
	return ans;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> k >> c;
		for(int j = 1;j <= k;j++) str += c;
	}
	cout << my_mt(str);
	return 0;
}

