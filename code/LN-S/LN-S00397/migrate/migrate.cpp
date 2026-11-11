#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int x[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, T;
	cin >> c >> T;
	while(T--){
		int n, d;
		cin >> n >> d;
		int sum[N];
		sum[0] = 0;
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
			sum[i] = x[i] - x[i - 1];
		}
		for(int i = 1; i <= n; i++){
			
	}
	return 0;
}
