#include <bits/stdc++.h>
using namespace std;
const int M = 2e6+ 5;
long long a[M];
vector<pair<int,int>> e;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
   	cin >> c >> t;
   	while(t--){
   		int n;
   		long long d;
		cin >> n >> d;
		long long x;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}	
		x = a[2] - a[1];
		long long l = d / x * 2;
		if(l == 0){
			cout << 0 << '\n';
			continue;
		}
		long long ans = n - l + 1;
		if(ans>0&&l!=2)cout << ans << '\n';
		else cout << 0 << '\n';
	}
}