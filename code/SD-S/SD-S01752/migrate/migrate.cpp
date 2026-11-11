#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
long long X[2002000],DP[2002000],dis[2002000],cnt[2002000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,i,j,l,sum,ans;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(i = 1;i <= n;i++){
			scanf("%lld",&X[i]);
		}
		ans = 0;
		for(i = 1;i <= n;i++){
			dis[i] = 0;
			l = i;
			for(j = i+1;j <= n;j++){
				while(X[j] - X[l] > d){
					l++;
				}
				if(j == l){
					dis[j] = -1e10;
				}
				dis[j] = dis[l]+1;
			}
			for(j = 0;j <= n;j++){
				DP[j] = 0;
				cnt[j] = 0;
			}
			sum = 0;
			l = i;
			cnt[0] = 1;
			DP[i] = 1;
			for(j = i+1;j <= n;j++){
				if(dis[j] < 0){
					continue;
				}
				while(X[j] - X[l] > d){
					cnt[dis[l]] -= DP[l];
					l++;
				}
				DP[j] = cnt[dis[j]-1];
				cnt[dis[j]] += cnt[dis[j]-1];
				if(cnt[dis[j]-1] == 2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//n^2 easy.
