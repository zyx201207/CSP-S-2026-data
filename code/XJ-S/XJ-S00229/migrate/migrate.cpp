#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E6 + 10;
int c, T;
int n ,d;
int a[N];
priority_queue<int> q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--) {
		int ans = 0;
		map<int,int> mp;
		cin >> n >> d;
		int dta = INT_MAX;
		for(int i=1 ; i <=n; i++){
			cin >> a[i];
			dta = min (a[i],dta);
		} 
		if(dta < 0){
			for(int i=1 ; i <=n; i++){
				a[i] += dta;
			} 
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1;j <= n; j++){
				if(i!=j&&abs(a[i]-a[j]) <= d){
					mp[i] ++;
					mp[j] ++;
				}
			}
		}
		for(auto i:mp){
			if(i.second == 2){
				ans ++;
			}
		}
		cout << ans << endl;
	}
} 
