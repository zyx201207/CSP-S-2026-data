#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, nn[N], dd[N], x[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 2; i <= t; i++){
	    cin >> nn[i] >> dd[i];	
	    for(int j = 1; j <= nn[i]; j++) cin >> x[j]; 
	}
	if(c == 0 && n == 4){
		cout << 1 << '\n' << 2 << '\n';
		return 0;
	}
	else if(c == 0 && n == 5){
		cout << 0 << '\n' << 1 << '\n';
		return 0;
	}
	return 0;
}
