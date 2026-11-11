#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c,t,n,d;
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
            cin >> x[i];
		}
		if(d == 1){
			cout << 0 << "\n";
			continue;
		}
		int cha = x[2] - x[1];
		bool isd = 1;
		for(int i = 1;i < n;i++){
			if((x[i + 1] - x[i]) != cha) isd = 0;
		}
		if(isd){
			if(d * 2 <= n){
				cout << n - d * 2 + 1;
			}else cout << 0;
		}
		cout << "\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/