#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d,ans;
int x[2000002];
int lst[2000002],nxt[2000002];
int f[5002][5002];
int sum[5002][5002];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		x[0]=-0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		x[n+1]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++){
			int l=1,r=i;
			while(l<=r){
				int mid=(l+r)>>1;
				if(x[i]-x[mid]<=d){
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			lst[i]=l;
			l=i,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(x[mid]-x[i]<=d){
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			nxt[i]=r;
		}
		for(int i=1;i<=n;i++){
			int p=i,top=0;
			f[i][i]=1;
			sum[i][i]=1;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[top]>d){
					top=max(i,lst[j]);
					if(top>=p){
						p=j;
					}
				}
				f[i][j]=min(3ll,sum[i][p-1ll]-sum[i][top-1ll]);
				sum[i][j]=sum[i][j-1]+f[i][j];
				if(f[i][j]==2){
					++ans;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
gaoyi loser.meishang 300.tuiyile.

worengranzai,wurenwenjindeyinyumeishizhidi.
hezheyuyin,hengzhemeiyoutingzhongdegequ.
*/