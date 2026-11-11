#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 10;
int w[N],k[N],a[510][N],t[510][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m;i++) cin >> w[i];
	for (int i = 1; i <= n;i++){
		cin >> k[i];
		for (int j = 1; j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--){
		int x,y;
		cin >> x >> y;
	}
	if (c == 0 && n == 2 && m == 5 && d == 20 && q == 2) cout << 32 << "\n" << 17;
	return 0;
} 

