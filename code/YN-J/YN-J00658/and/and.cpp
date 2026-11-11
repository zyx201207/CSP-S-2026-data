#include <bits/stdc++.h>
using namespace std;
int am, bm, cm, dm;
cin >> am >> bm >> cm >> dm;

int main() {
	//frozpen("and","r",stdin)
	//frozpen("and","w",stdout)
	int n;
	cin >> n;
	cin >> m;
	string a, b, c, d;
	f (int i = 1; i <= n; i++) {
		if (am and bm < am and cm) {
			cout << cm << endl;
		} else if (am and bm < am and dm) {
			cout << dm << endl;
		} else if (am and cm < am and bm) {
			cout << bm << endl;
		} else if (am and dm < cm and am) {
			cout << am << endl;
		}
	}
	return 0;
}
