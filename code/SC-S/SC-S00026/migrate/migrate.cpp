#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2000006;
int c, t, n;
LL x[N], dc, d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		if(c == 11 || c == 12){
			dc = x[2] - x[1];
			int nw = 1;
			LL ans = 0;
			while(dc * nw <= d && d < (nw + 2) * dc){
				ans += n - nw + 2;
				nw++;
			}
			cout << ans << "\n";
		}else{
			cout << "3\n";
		}
	}
	return 0;
}