#include <bits/stdc++.h>
#define double long double
#define int long long
#define ull unsigned long long
#define ve vector<int>
#define pii pair<int, int>
#define vi vector<int, int>
#define endl '\n'
using namespace std;
const int N = 1e8 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
int a[N];
void solve() {
	cin >> n >> m;
	int ok_dengcha = 0;
	for (int i = 1; i <= n; i ++) {
  		cin >> a[i];
	}
	sort(a + (int)1, a + n + (int)1);
	int cha = a[2] - a[1];
	for (int i = 3; i <= n; i ++) {
		if (a[i] - a[i - 1] != cha) {
		   	ok_dengcha = 1;
		}
	}
	if (ok_dengcha == 0) {
		int w = sqrt((double)1 + (double)m / (double)cha * (double)8.0);
		int sum = (w - 1) / 2 + 1;
		if (sum > n) {
		   	cout << n;
		}
	 	else {
		 	cout << sum;
		 }
	}
	else {
		int mx = 0;
		for (int i = 1; i <= n; i ++) {
			int cnt = 0;
			int mm = m;
			for(int j = i; j >= 1; j --) {
				mm -= (a[i] - a[j]);
				if (mm>=0) cnt++;
			}
			mx = max(mx,cnt);
		}
		cout << mx;
	}

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int t = 1;
//	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}