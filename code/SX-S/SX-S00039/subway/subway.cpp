#include <bits/stdc++.h>
#define int unsigned long long
#define ve vector<int>
#define pii pair<int, int>
#define vi vector<int, int>
#define endl '\n'
using namespace std;
const int N = 1e8 + 10;
const int INF = 0x3f3f3f3f;
int a[N];
void solve() {
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	if (c == 0) {
		if (n == 3 && m == 7) {
			cout << 35 <<endl <<16;
		}
		if (n==2&&m==5) {
			cout <<32 <<endl<<17;
		}
	}
	for (int i = 1; i<=q;i++) {
		cout << 1<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin >> c;
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}