#include <bits/stdc++.h>
using namespace std;

const int iop = 0x3f3f3f3f;
int n, d;
int ans = 0;
int c, t;

int main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	//ios :: sync_with_stdio(0);
	//cin.tie(0);
	   
	cin >> c >> t;
	
	while(t --) {
		cin >> n >> d;
		vector<long long> x(n + 1);
		vector<int> nex(n + 1, 0), las(n + 1, iop);
		for(int i = 1;i <= n;++ i)
			cin >> x[i];
		
		for(int i = 1;i <= n;i ++) {
			int pl = i + 1;
			while(x[pl] <= x[i] + d && pl <= n) pl ++;
			nex[i] = pl - 1;
			las[pl - 1] = i;		
		}	
		
		for(int i = 1;i <= n;++ i)
			if(las[i + 1] < i && nex[i] > i + 1) ans ++;
	
		cout << ans << "\n";
		ans = 0;	
	}
	
	return 0;
}