#include <bits/stdc++.h>
using namespace std;
const int Maxn = 5e5 + 5;
int n;
long long res, ans, pos, nxt;
long long m;
long long a[Maxn];
long long s[Maxn];
bool cmp(int x, int y){
	return x < y;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		s[i] = a[i] - a[i - 1];
	}
	pos = 1;
	for(int i = 1; i <= n; i++){
		pos++;
		res += s[i] * (pos - 1);
		nxt += s[i];
		while(res > m){
			res -= nxt;
			nxt -= s[i - pos + 1];
			pos--;
		}
		ans = max(ans, pos);
	}
	cout << ans << endl;
	return 0;
}
