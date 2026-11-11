#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long ll;
ll n, ans;
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (ll i = 1;i <= n;i++) {
		ll a;
		string c;
		cin >> a >> c;
		for (int j = 1;j <= a;j++)
			s += c;
	}
	for (ll i = 0;i < s.size() / 2;i++) {
		if (s[i] != s[s.size() - i - 1])
			ans++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}