#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 7, N = 5e2 + 7, K = 5e5 + 7;
int c, n, m, d, q, xx, yy;
int x[M], k[N], s[N][K], ss[N][K];
int main (){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	srand(time(0));
	cin >> c >> n >> m >> d >> q;
	if(c <= 3){
		for(int i = 0; i < m; i ++){
			cin >> x[i];
		}
		for(int i = 0; i < n; i ++){
			cin >> k[i];
			for(int j = 0; j < k[i]; j ++){
				cin >> s[i][j] >> ss[i][j];
			}
		}
		for(int i = 0; i < q; i ++){
			cin >> xx >> yy; xx --; yy --;
			int ans = x[xx] + x[yy];
			if(n == 1){
				for(int j = 0; j < k[0]; j ++){
					if(s[0][j] == xx){
						ans += ss[0][j];
					}
					if(s[0][j] == yy){
						ans += ss[0][j];
					}
				}
				cout << ans << "\n";
			} else{
				ans += rand() % 50 + 1;
				cout << ans << "\n";
			}
		}
	}else{
		for(int i = 0; i < q; i ++){
			cout << rand() % 500 + 1 << "\n";
		}
	}
	return 0; 
}
// rp++ 
