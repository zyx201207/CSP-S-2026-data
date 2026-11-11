#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> a >> b;
	for (int i = 1; i <= b; i++){
		cout << i % 500005 + 1 << endl;
	}
	return 0;
}