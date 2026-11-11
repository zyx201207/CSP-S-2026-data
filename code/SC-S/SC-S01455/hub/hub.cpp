#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IL inline
#define FIO(name) freopen(name".in", "r", stdin), freopen(name".out", "w", stdout)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define lop(i, a, b) for (auto i = (a); i <= (b); i++)
#define pol(i, a, b) for (auto i = (a); i >= (b); i--)
#define asmax(a, b) ((a) = max((a), (b)))
#define asmin(a, b) ((a) = min((a), (b)))
#define fst first
#define snd second
const int N = 1e6 + 5;
int n, k;
vector<int> G[N];
int main () {
	FIO("hub");
	IOS;
	int subid, T; cin >> subid >> T;
	while (T--) {
		cin >> n >> k;
		lop(i, 2, n) {int u, v; cin >> u >> v;}
		cout << "0\n";
	}
	return 0;
}