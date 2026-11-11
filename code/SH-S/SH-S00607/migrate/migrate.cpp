#include<bits/stdc++.h>
using namespace std;
long long n, d;
long long a[2000001], tmp[15];
void dfs(long long now, long long lim, long long cnt){
	if(now > lim) return;
	if(now == lim){
		tmp[cnt]++;
	}
	long long i = now + 1;
	while(a[i] <= a[now] + d){
		dfs(i, lim, cnt + 1);
		i++;
	}
} 
bool ck(long long x, long long y){
	memset(tmp, 0, sizeof(tmp));
	dfs(x, y, 0);
	for(long long i = 2; i <= n; i++){
		if(tmp[i]){
			return tmp[i] == 2;
		}
	}
	return 0;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	if(c <= 2){
		while(t--){
			cin >> n >> d;
			for(long long i = 1; i <= n; i++){
				cin >> a[i];
			}
			long long ans = 0;
			for(long long i = 1; i <= n; i++){
				for(long long j = i + 3; j <= n; j++){
					if(ck(i, j)) ans++;
				}
			}
			cout << ans << "\n";
		}
	}
}
/*
LUOGU UID 1549034

ίχίχίχ 
*/ 
