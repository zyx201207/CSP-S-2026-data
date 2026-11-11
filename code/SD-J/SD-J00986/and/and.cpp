#include<iostream>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,a[200005],ans;
pii dp[200005];
void dfs(int now,int val,int cnt){
	if(val<ans) return;
//		cout<<now<<" "<<val<<" "<<cnt<<endl;
	if(cnt==m){
		ans=max(ans,val);
		return;
	}
	if(now>n) return;
	for(int i=now+1;i<=n+1;i++){
		dfs(i,val&a[now],cnt+1);
		dfs(i,val,cnt);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		printf("%d",ans);
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		printf("%d",ans);
		return 0;
	}
	if(m==2){
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)
				ans=max(ans,a[i]&a[j]);
		printf("%d",ans);
		return 0;
	}
	if(n<30){
		dfs(1,0x6fffffff,0);
		printf("%d",ans);
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){//error dp
			dp[i]={a[i],1};
			for(int j=1;j<=i;j++){
				if(a[i]&dp[j].fi>dp[i].fi)
					dp[i]={a[i]&dp[j].fi,dp[j].se+1};
				if(a[i]&a[j]>dp[i].fi)
					dp[i]={a[i]&a[j],2};
			}
		}
		printf("%d",dp[n].fi);
	}
	return 0;
} 
