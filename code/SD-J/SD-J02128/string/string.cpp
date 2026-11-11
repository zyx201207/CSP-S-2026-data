#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n;
struct S {
	int a;
	char c;
}s[MAXN];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i].a >> s[i].c;
	bool f = true;
	char ch = s[1].c;
	if(n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 2; i <= n; i++) {
		if(s[i].c != ch) {
			f = false;
			break;
		}
	}
	if(f == true) {
		cout << 0 << '\n';
		return 0;
	}
	long long sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += s[i].a;
	}
	string str = "";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= s[i].a; j++) {
			str += s[i].c;
		}
	}
	long long ans = 0;
	if(sum % 2 == 0) {
		for(int i = 1; i <= sum / 2 + 1; i++) {
			if(str[i - 1] != str[sum - i]) ans++;
		}
	}
	else {
		for(int i = 1; i <= sum / 2; i++) {
			if(str[i - 1] != str[sum - i]) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
} 
