#include<bits/stdc++.h>  //rp++
#define int long long
using namespace std;
int c,T;
int n,d,cnt,lst,ans,sum,csum;
int x[2000005];
int dp[2000005];
void solve(int le,int ri,int cnt){
//	printf("%lld %lld\n",le,ri);
	if(x[le + 1] - x[le] > d){
		sum = -1;
		return ;
	}
	int l = le,r = ri,mid;
	while(l < r){
		mid = (l + r) / 2;
		if(x[mid] <= x[le] + d) l = mid;
		else r = mid - 1;
		if(l + 1 == r){
//			printf("%lld %lld\n",x[r],x[le]);
			if(x[r] - x[le] <= d){
				l++;
				break;
			}
			break;
		}
	}
//	printf("%lld->%lld,%lld\n",le,l,ri);
	if(l >= ri){
		sum = cnt + 1; 
		return ;
	}
	solve(l,ri,cnt + 1);
}
void check(int l,int r,int cnt){
//	printf("%lld,%lld\n",l,r);
	if(cnt > sum) return ;
	if(l == r){
		csum++;
		return ;
	}
	for(int j = l + 1;j <= r;j++){
		if(x[j] - x[l] > d) return ;
		check(j,r,cnt + 1);
		if(csum > 2) return ;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		ans = 0;
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&x[i]);
			for(int j = 1;j < i;j++){
				csum = 0;
				sum = 0;
				solve(j,i,0);
				check(j,i,0);
				if(csum == 2){
//					printf("%lld,%lld:%lld\n",j,i,sum);
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
