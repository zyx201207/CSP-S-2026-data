#include<iostream>
#include<cstring>
using namespace std;
int c,t,n;
long long d,x[200005];
long long minn[15][15],cnt[15][15],dp[5005],q[5005];
void dfs(int st,int p,int Cnt){
	if(minn[st][p]>Cnt){
		minn[st][p]=Cnt;
		cnt[st][p]=1;
	}
	else if(minn[st][p]==Cnt) cnt[st][p]++;
	for(int i=p+1;i<=n;i++){
		if(x[i]-x[p]<=d) dfs(st,i,Cnt+1);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==11||c==12){
		while(t--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
			long long dis=x[2]-x[1];
			int c=d/dis;
			if(n-1<2*c-1||d<dis||c==1) printf("%d\n",0);
			printf("%d\n",n-(2*c-1));
		}
		return 0;
	}
	else if(c==1||c==2){
		while(t--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%d",&x[i]);
			long long ans=0;
			memset(minn,0x3f,sizeof minn);
			for(int i=1;i<n;i++){
				dfs(i,i,0);
			}
			for(int i=1;i<n;i++){
				for(int j=1;j<=n;j++){
					if(cnt[i][j]==2) ans++;
				}
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	while(t--){
		long long ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		for(int i=1;i<n;i++){
			memset(dp,0x3f,sizeof dp);
			memset(q,0,sizeof q);
			dp[i]=0;
			q[0]=i;
			int r=0,f=0;
			for(int j=i+1;j<=n;j++){
				while(f<r&&x[j]-x[q[f]]>d) f++;
				long long z=dp[q[f]];
				dp[j]=z+1;
				while(f<=r&&dp[j]<=dp[q[r]]) r--;
				q[r++]=j;
			}
			for(int j=i+3;j<=n;j++){
				if(dp[j]-1==dp[j-1]&&dp[j]-1==dp[j-2]&&dp[j-1]-1!=dp[j-3]) ans++;
				else if(dp[j]-1==dp[j-1]&&dp[j]-1==dp[j-2]&&dp[j-1]-1==dp[j-3]) break;
			}
		}
		printf("%lld\n",ans); 
	}
	return 0;
} 
