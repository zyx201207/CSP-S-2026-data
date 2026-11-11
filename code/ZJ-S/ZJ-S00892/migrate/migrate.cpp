#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
long long d;
long long a[maxn];
int f(long long x){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]<=x) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c<=10){
		while(t--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			long long num[5005][5005]={},ans=0;
			for(int i=1;i<=n;i++){
				int to=i,cnt=0;
				while(to<n){
					to=f(a[to]+d);
					num[i][to]=++cnt;
				}
				long long last=1e18;
				for(int j=n;j>0;i--){
					if(num[i][j]!=0) last=min(last,num[i][j]);
					num[i][j]=last;
				}
			}
			int l=1,r=1;
			long long dp[5005]={};
			while(r<=n){
				while(f(a[l]+d)>f(a[r]-d)+1) r++;
				if(f(a[l]+d)==f(a[r]-d)+1) dp[l]=r;
				l++;
			}
			for(int i=1;i<=n;i++){
				if(dp[i]==0) continue;
				ans++;
				int to=dp[i];
				while(to<=n){
					if(num[i][to]==2+to-dp[i]) ans++;
					to++;
				} 
				//?
			}
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}
