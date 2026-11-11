#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); i ++)
#define DEP(i, r, l) for (int i = (r); i >= (l); i --)
#define fi first
#define se second
#define pb emplace_back
#define mems(a, v) memset((a), (v), sizeof(a))
#define memc(a, b) memset((a), (b), sizeof(a))
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)((x).size())
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 1e6 + 5;
	string F = "migrate";
	int C = 6;
	int main() {
		string cc = "g++ " + F + ".cpp -o " + F + " -O2 -Wl,--stack=1000000000";
		cerr << cc << '\n';
		system(cc.c_str());
		REP(i, 1, C) {
			string in = F + to_string(i) + ".in";
			string ans = F + to_string(i) + ".ans";
			string iin = F + ".in";
			string out = F + ".out";
			system((F + " < " + in).c_str());
			string tt = "fc " + F + ".out " + F + to_string(i) + ".ans";
			cerr << tt.c_str() << '\n';
			assert(!system(tt.c_str()));
		}
		return 0;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}