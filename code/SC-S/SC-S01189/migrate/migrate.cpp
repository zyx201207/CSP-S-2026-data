#include<bits/stdc++.h>
using namespace std;


int main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false),cin.tie(0);
	int c, t;cin >> c >> t;
	while(t--){
		int n, d;cin >> n >> d;
		vector<int> A(n + 1);
		for(int i = 1;i <= n; i++){
			cin >> A[i];
		}
		int L = 2 * d - 1, ans = 0;
		for(int i = 1;i <= n; i++){
			int af = *lower_bound(begin(A) + i, end(A), i + L);
			if(af - i == L) ans++;
		}
		cout << ans << '\n';
	}
	
	
	
	return 0;
}