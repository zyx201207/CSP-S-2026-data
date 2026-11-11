#include<bits/stdc++.h>
using namespace std;
int c,t,n,nxt[2000005],cnt[2][5005];
long long d,x[2000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i) scanf("%lld",&x[i]);
		for(int i=1,j=1;i<=n;++i){
			while(j+1<=n && x[j+1]-x[i]<=d) ++j;
			nxt[i]=j;
		}
		long long ans=0,tt=0;
		for(int i=1;i<=n;++i){
			memset(cnt[tt],0,sizeof cnt[tt]);
			cnt[tt][i]=1;
			int la=i;
			while(nxt[la]>la){
				tt^=1;
				memset(cnt[tt],0,sizeof cnt[tt]);
				for(int i=1;i<=n;++i){
					for(int j=i+1;j<=nxt[i];++j) cnt[tt][j]=min(3,cnt[tt][j]+cnt[tt^1][i]);
				}
				for(int i=1;i<=n;++i){
					if(i>la && cnt[tt][i]==2) ++ans;
				}
				la=nxt[la];;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
