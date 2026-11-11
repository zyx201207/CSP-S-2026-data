#include<bits/stdc++.h>
using namespace std;
struct str{
	long long a;
	string c;
}s[300000];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].c;
	}
	string q;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= s[i].a; j++) {
			q += s[i].c;
		}
	}
	long long ans = 0;
	for(int i = 0; i < q.size() / 2; i++) {
		if(q[i] != q[q.size() - 1 - i]) ans++;
	}
	cout << ans;
	return 0;
}
