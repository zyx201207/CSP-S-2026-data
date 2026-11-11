#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for(int i = j; i <= k; i++)
#define MaxN 100005
#define int long long

int c, n, m, d, q;
int w[MaxN];
int k[MaxN], a[MaxN][MaxN], t[MaxN][MaxN];
int x, y;
int tong[MaxN];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w", stdout);
	cin >> c >> n >> m >> d >> q;
	For(i, 1, m) cin >> w[i];
	For(i, 1, n){
		cin >> k[i];
		For(j, 1, k[i]){
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	while(q--){
		cin >> x >> y;
		For(i, 1, n){
			int f1 = 0, f2 = 0;
			For(j, 1, k[i]){
				if(a[i][j] == x) f1 = 1;
				if(a[i][j] == y) f2 = 1;
			}
		}
		cout << w[x] + w[y] << endl;
	}
    return 0;
}
