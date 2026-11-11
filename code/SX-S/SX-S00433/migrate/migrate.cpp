#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int c,t;
int nN;
long long d,aA[N+5];
long long ans;
int n;
long long a[N+5];
int isok[N+5],nxt[N+5];
long long dp[N+5][2],cdp[N+5][2];
void work(){
//	if(n<=3) return;
	for(int i=1;i<=n;i++) isok[i]=nxt[i]=dp[i][0]=dp[i][1]=cdp[i][0]=cdp[i][1]=0;
	int r=1;
	for(int i=1;i<=n;i++){
		while(r+1<=n&&a[r+1]-a[i]<=d) r++;
		nxt[i]=r;
//		printf("%d->%d\n",i,nxt[i]);
	}
	for(int i=1;i<=n;i++){
		int j=nxt[i],k=nxt[j];
		isok[i]=0;
		if(j==n) continue;
		if(i<j-1&&a[k]-a[j-1]<=d) isok[i]++,j--;
		if(i<j-1&&a[k]-a[j-1]<=d) isok[i]++,j--;
//		printf(":%d\n",isok[i]);
	}	
	for(int i=1;i<=n;i++){
		if(isok[i]<2) cdp[i][0]++,dp[i][0]++;
		if(i==n) break;
		if(isok[i]<2) dp[nxt[i]][isok[i]]+=dp[i][0];
		if(isok[i]<1) dp[nxt[i]][1]+=dp[i][1];
		if(isok[i]<2){
			cdp[nxt[i]][isok[i]]+=dp[i][0];
			int j=nxt[i],k=nxt[j]-1;
			if(isok[i]==0&&j<k&&j!=n&&i<j-1&&a[k]-a[j-1]<=d) cdp[nxt[i]][isok[i]]-=dp[i][0];
//			if(isok[i]==1&&j<nxt[nxt[j]]&&j!=n&&i<j-1&&a[nxt[nxt[j]]]-a[j-1]<=d) cdp[nxt[i]][isok[i]]-=dp[i][0];
		}
		if(isok[i]<1) cdp[nxt[i]][1]+=dp[i][1];
	}
	for(int i=1;i<=n;i++){
		int j=nxt[i],k=nxt[j];
		if(j==n) continue;
		//[j+1,k]
		int l1,l2;
		//>=l1 -> +=0
		//[l2,l1-1] -> +=1
		if(!(i<j-1)) l1=l2=j+1;
		else{
			j--;
			l1=nxt[j]+1;
			if(!(i<j-1)) l2=j+2;
			else{
				j--;
				l2=nxt[j]+1;
			}
		}
		ans+=1ll*cdp[i][0]*max(0ll,l1-l2);
		ans+=1ll*cdp[i][1]*max(0ll,k-l1+1);
//		printf("%d:%lld %d %d %d %d\n",i,ans,dp[i][0],dp[i][1],cdp[i][0],cdp[i][1]);
	}
}
void solve(){
	ans=0;
	scanf("%lld%lld",&nN,&d);
	int l=1;
	for(int i=1;i<=nN;i++){
		scanf("%lld",&aA[i]);
		if(i!=1&&aA[i]-aA[i-1]>d){
			n=0;
			while(l<i) a[++n]=aA[l],l++;
			work();
		}
	}
	n=0;
	while(l<=nN) a[++n]=aA[l],l++;
	work();	
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	t--;
	while(t--) solve();
	return 0;
}
