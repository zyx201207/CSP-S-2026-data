#include<bits/stdc++.h>
#define IO freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
#define huh
using namespace std;
typedef long long ll;
int c,t;
int n;
ll d;
ll A[2000010];
#ifdef huh
int dp[2000010];
int is[2000010];
void solve(){
	int ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",&A[i]);
	for(int i=2;i<=n;i++){//枚举右端点
		int r=i;
		dp[i]=0;
//		memset(dp,0,sizeof dp);
		for(int j=i-1;j>=1;j--){
			ll visb=A[j]+d;
			while(r&&A[r]>visb)r--;
			if(r==j)break;//hou mian de dou bu ke da
			dp[j]=dp[r]+1;
			if(r-1>j&&dp[r]==dp[r-1]){
			//	printf("j:%d r:%d i:%d   %d %d %d\n",j,r,i,dp[r],dp[r-1],dp[r-2]);
				if((r-2>j&&dp[r-2]!=dp[r])||(r-2<=j)){
					ans++;
//					printf("[%d %d]\n",j,i);
					is[j]=1;
				}
			}
			if(r-j==1){//如果他确定了下一个，那么下一个说不定回
				if(is[r])is[j]=1,ans++;
			}
		}
	//	printf("dp: ");for(int j=1;j<=i;j++)printf("%d ",dp[j]);puts("");
	}
	printf("%d\n",ans);
}
#else
pair<int,int>check(int now,int sum,int l,int r){
	if(now==r){
//		printf("[%d %d]\n",sum,1);
		return {sum,1};
	}
	ll visb=A[now]+d;
	pair<int,int>ret={1e9,0};
	//printf("%lld\n",visb);
	printf("%d %d %d %d\n",now+1<=r,A[now+1]<=visb);
	for(int i=now+1;i<=r&&A[i]<=visb;i++){
		puts("shdsfhsj");
		pair<int,int>gt=check(i,sum+1,l,r);
		if(gt.first<ret.first)ret=gt;
		else ret.second+=gt.second;
	}
	return ret;
}
void solve(){
	int ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",&A[i]);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
//			ans+=check(j,i);
			pair<int,int>gt=check(i,0,j,i);
			printf("(%d %d)\n",gt.first,gt.second);
			if(gt.second==2){
				ans++;
			//	printf("[%d %d]\n",j,i);
			}
		}
	}//puts("");
	printf("%d\n",ans);
}
#endif
signed main(){
	IO;
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
}