#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
char s[200005 * 505];
int n, l = 0, ans = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		int sum;
		char c;
		cin >> sum >> c;
		for (int i = l + 1; i <= l + sum; i++) s[i] = c;
		l += sum;
	}
	for (int i = 1; i <= l / 2; i++){
		if (s[i] != s[l + 1 - i])
			ans++;
	}
	cout << ans;
	return 0;
} 

