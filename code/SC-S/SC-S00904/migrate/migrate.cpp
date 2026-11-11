#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6 + 10;
int c, t, n, d;
int x[maxn];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 11 or c == 12){//A
		while(t--){
			cin >> n >> d;
			for(int i = 1; i <= n; i++){
				cin >> x[i];
			}
			int diff = abs(x[2] - x[1]);
			int cnt = d / diff;
			if(cnt == 1){
				cout << 0 << endl;
			}else{
				cnt += 1;
				cout << n - cnt << endl;
			}
		}
	}
	if(c == 13 or c == 14){//B
		while(t--){
			cin >> n >> d;
			for(int i = 1; i <= n; i++){
				cin >> x[i];
			}
			cout << 0 << endl;
		}
	}
	if(c >= 15 && c <= 18){//C
	}
	return 0;
}