#include <bits/stdc++.h>
#define MAXN (2000200)
using namespace std;
int C, T;
long long D, N, X[MAXN];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while(T --) {
		cin >> N >> D;
		for(int i=1;i<=N;i++) cin >> X[i];
		if(N == 1) cout << "0\n";
		if(C == 11 || C == 12) {
			long long del = X[2] - X[1];
			long long mxl = D / del;
			mxl = 2*mxl - 1;
			long long ans;
			if(mxl == 1) ans = 0;
			else ans = max(0, N - mxl);
			cout << ans << '\n';
		}
	}
	return 0;
}
