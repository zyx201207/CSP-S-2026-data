#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 5;

int main() {
	int cnt = 0;
	while (cnt <= 1000) {
		assert(!system("./gen"));
		assert(!system("./migrate"));
		assert(!system("./bf"));
		if(system("diff migrate.out migrate.ans -Z")) {
			return 0;
		}
		cerr << ++cnt << '\n';
	}

	return 0;
}