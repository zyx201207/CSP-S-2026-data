#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s = "";
	for(int i = 1;i <= n;i++) {
		int a;
		char c;
		cin >> a >> c;
		while(a--) s += c;
	}
	int l = (int) s.size();
	int ans = 0;
	if(l & 1) {
		for(int i = l / 2 - 1, j = l / 2 + 1;i >= 0 && j < l;i--, j++) {
			if(s[i] != s[j]) ans++;
		}
	}
	else {
		for(int i = l / 2 - 1, j = l / 2;i >= 0 && j < l;i--, j++) {
			if(s[i] != s[j]) ans++;
		}
	}
	cout << ans;
	return 0;
}
