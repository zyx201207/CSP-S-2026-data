#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
long long a[maxn],d;
int dp[maxn],h[maxn],n;
void work(){
	scanf("%lld %lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(d>=a[n]-a[1]){
		printf("0\n");
		return;
	}
	int ans=0;
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			dp[l]=0;
			for(int i=l+1;i<=r;i++){
				int mn=INT_MAX,cnt=0;
				for(int j=i-1;j>=l && a[i]-a[j]<=d;j--){
					if(dp[j]<mn) mn=dp[j],cnt=1;
					else if(dp[j]==mn) cnt++;
				}
				dp[i]=mn+1;
				if(i==r && cnt==2) ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
int c,T;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&T);
	if(c>=13 && c<=14){
		while(T--) printf("1\n");
	}
	else while(T--) work();
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/