#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6;
const int LOG = 21;
int C,T;
namespace Elaina {
	int n; ll d;
	ll x[maxn + 5];
	int nxt[maxn + 5];  // 从 u 向后走 1 步到达的最远位置 v  (n + 1) 表示后面没有可达点
	int f[maxn + 5][25]; // 从 u 向后走 2^k 步到达的最远位置 v
	void initf() {
		for (int i = 1;i <= n + 1;i ++) for (int j = 0;j <= LOG;j ++) f[i][j] = n + 1;
		for (int i = 1;i <= n;i ++) f[i][0] = nxt[i];
		for (int j = 1;(1 << j) <= n;j ++) for (int i = 1;i <= n;i ++) f[i][j] = f[f[i][j - 1]][j - 1];
	}
	void CLEAR() {
		
	}
	void main() {
		CLEAR();
		cin >> n >> d;
		for (int i = 1;i <= n;i ++) cin >> x[i];
		cout << 1ll * n * (n - 2) - 1 << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> C >> T;
	while (T --) Elaina::main();
	return 0;
}