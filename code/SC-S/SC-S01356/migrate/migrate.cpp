# include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e3+5;
int c,t;

signed main(){
	
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		int n,d,ans = 0;
		cin >> n >> d;
		int x[n+5] ={0};
		for(int i = 1;i <= n;i++){
			cin >> x[i];
			if(i>=3 && x[i-1] - x[i] <= d && x[i-2] - x[i-1] <= d && x[i-3] - x[i-2] <= d){
				ans=ans+1;
			}
		}
		cout << ans << "\n";
	}
	
	
	return 0;
} 