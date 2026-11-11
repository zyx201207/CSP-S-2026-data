#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,T;
namespace sub1{
	int n,dis[5010],f[5010],inf=0x3f3f3f3f,ans;
	ll d,a[5010];
	void solve(){
		while(T--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++) dis[j]=inf,f[j]=0;
				dis[i]=0,f[i]=1;
				for(int j=i;j<=n;j++){
					if(f[j]==2){
						ans++;
//						printf("%lld %lld\n",a[i],a[j]);
					}
					for(int k=j+1;k<=n;k++){
						if(a[k]>a[j]+d) break;
						if(dis[j]+1<dis[k]){
							dis[k]=dis[j]+1;
							f[k]=f[j];
						}else if(dis[j]+1==dis[k]){
							f[k]=min(f[k]+f[j],inf);
						}
	//					printf("%d -> %d(%d,%d)\n",j,k,dis[k],f[k]);
					}
				}
			}
			printf("%d\n",ans);
		}
	}
}
namespace sub2{
	int n;
	ll d,a[2000010];
	void solve(){
		while(T--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			d/=a[2]-a[1];
			if(d<=1) printf("0\n");
			else printf("%lld\n",max(n-(d*2-1),0ll));
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c==11||c==12) sub2::solve();
	else sub1::solve();
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/