#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define ve vector<int>
#define pii pair<int, int>
#define vi vector<int, int>
#define endl '\n'
using namespace std;
const int N = 1e8 + 10;
const int INF = 0x3f3f3f3f;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	cin >> c;

	int t = 1;
	cin >> t;
	while(t --) {
		if (t % 2 == 1) {
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}
	return 0;
}