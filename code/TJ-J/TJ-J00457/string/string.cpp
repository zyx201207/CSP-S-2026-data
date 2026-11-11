#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, ans = 0;
	cin >> n;
	string s;
	while(n--) {
		int a;
		char c;
		cin >> a >> c;
		for(int i = 1; i <= a; i++) s += c;
	}
	int x = s.size();
	if(x % 2 == 0) {
		string a1, b1;
		for(int i = 0; i < x / 2; i++) a1 += s[i];
		for(int i = x / 2; i < x; i++) b1 += s[i];
		reverse(b1.begin(), b1.end());
		for(int i = 0; i < x / 2; i++) {
			if(a1[i] != b1[i]) ans++;
			else continue;
		}
	} else {
		string a1, b1;
		for(int i = 0; i < x / 2; i++) a1 += s[i];
		for(int i = x / 2 + 1; i < x; i++) b1 += s[i];
		reverse(b1.begin(), b1.end());
		for(int i = 0; i < x / 2; i++) {
			if(a1[i] != b1[i]) ans++;
			else continue;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
