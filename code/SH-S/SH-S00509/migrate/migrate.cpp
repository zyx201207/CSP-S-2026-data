#include<bits\stdc++.h>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 10;
int s[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--){
		int n, d;
		cin >> n >> d;
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i++){
			cin >> s[i]; 
		}
		if (n == 1){
			cout << 0 << '\n';
			continue;
		}
		int m = s[2] - s[1];
		if (m >= d){
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		for (int i = 4; i <= n; i++){
			int nd = (i-1) * m;
			if (d < nd && d >= nd - m) ans += n - i + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
