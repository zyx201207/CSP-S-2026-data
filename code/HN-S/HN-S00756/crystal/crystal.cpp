#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5 + 5;

int n;
ll a[N], s[N], m;

int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 1;
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
		while(ans < i && s[i] - s[i - ans - 1] + m >= (ans + 1) * a[i])ans++;
	}
	cout << ans << '\n';
	return 0;
}