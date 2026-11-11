#include<bits/stdc++.h>
using namespace std;
int c, T, n;
long long d, a[2000010];
pair<int, long long> f[2000010];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	for(; T--; ){
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				f[j].first = 1 << 30, f[j].second = 0;
			}
			f[i].first = 0, f[i].second = 1;
			for(int j = i; j <= n; j++){
				if(f[j].second == 2){
					ans++;
				}
				int L = j, R = n + 1;
				while(L + 1 < R){
					int M = (L + R) >> 1;
					if(a[M] - a[j] <= d){
						L = M;
					}
					else{
						R = M;
					}
				}
				for(int l = L; l >= max(j, L - 2); l--){//Caution!!!
					if(f[j].first + 1 < f[l].first){
						f[l].first = f[j].first + 1;
						f[l].second = f[j].second;
					}
					else if(f[j].first + 1 == f[l].first){
						f[l].second += f[j].second;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}