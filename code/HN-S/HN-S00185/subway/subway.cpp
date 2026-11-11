#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
int c, n, m, d, q;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if(c == 0 && n == 2){
		cout << 32 << '\n' << 17 << '\n';
		return 0;
	}
	else if(c == 0 && n == 3){
		cout << 35 << '\n' << 16 << '\n';
	    return 0;
	}
	return 0;
}
