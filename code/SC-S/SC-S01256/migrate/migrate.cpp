#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, t, n, d, minx;
int arr[2000005];

int flag, cs;
void pd(int x, int y, int s){
	if(x == y){
		if(s < minx){
			minx = s;
			cs = 1;
			return ;
		}
		if(s == minx){
			cs++;
			return ;
		}
		return ;
	}
	if((c == 13 || 14) && s > 2){
		return ;
	}
	for(int i = x + 1; i <= y; i++){
		if(arr[i] - arr[x] <= d){
			pd(i, y, s + 1);
		}
	}
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int T = 1; T <= t; T++){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				minx = 999999999999999, cs = 0;
				pd(i, j, 0);
				if(cs == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
