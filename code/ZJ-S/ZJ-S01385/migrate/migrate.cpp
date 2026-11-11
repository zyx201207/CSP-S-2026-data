#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long lft[N],rgt[N],dp[N],a[N],cnt;
void dfs(long long now,long long ed,long long step){
	if(cnt>=3)return;
	if(rgt[now]>=ed){
		if(step+1==dp[ed])cnt++;
		return;
	}
	for(long long i=rgt[now];i>=now+1;i--){
		if(cnt>=3)return;
		dfs(i,ed,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(c==11||c==12){
			long long k=d/(a[2]-a[1]);
			k=(2*k-1);
			if(k<=2||k>=n){
				printf("0\n");
				continue;
			}
			long long ans=n-k;
			printf("%lld\n",ans);
			continue;
		}
		for(long long i=1;i<=n;i++){
			rgt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			lft[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			dp[i]=0;
			for(long long j=i+1;j<=n;j++){
				dp[j]=dp[max(i,lft[j])]+1;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
