#include<bits/stdc++.h>
using namespace std;
bool huiwen(string s) {
	for (long long i = 0; i < s.size(); i++) {
		long long j = s.size()-1-i;
		if (s[i] != s[j]) {
			return 0;
		}
		if (i == j) break;
	}
	return 1;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, ans = 0;
	cin>>n;
	string s = "";
	for (long long i = 1; i <= n; i++) {
		long long num;
		string str;
		cin>>num>>str;
		for (long long j = 1; j <= num; j++) {
			s += str;
		}
	}
	if (huiwen(s)) {
		cout<<0;
		return 0;
	}
	for (long long i = 0; i < s.size(); i++) {
		long long j = s.size()-1-i;
		if (s[i] != s[j]) {
			ans++;
			s[j] = s[i];
		}
		if (i == j) break;
	}
	cout<<ans;
	return 0;
}
