#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n; cin >> n; long long len = 0; int num[n + 1]; char c[n + 1]; string s = "";
	for (int i = 1;i <= n;i ++) {
		cin >> num[i] >> c[i]; len += num[i]; for (int j = 1;j <= num[i];j ++) s += c[i];
	}
	
	long long ans = 0;
	for (int i = 0;i < len / 2;i ++) {
		if (s[i] != s[len - i - 1]) ans ++;
	}
	cout << ans;
}