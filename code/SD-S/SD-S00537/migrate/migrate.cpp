#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n;
long long d,dis[N][N],f[N][N],a[N],ans=0;
void solve(){
	ans=0;
	scanf("%d %lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				dis[i][j]=f[i][j]=1;
			}
			else{
				f[i][j]=0;
				dis[i][j]=0x3f3f3f3f;
			}
		}
	}
	for(int len=1;len<=n;len++){
		for(int l=1,r;l+len-1<=n;l++){
			r=l+len-1;
			if(dis[l][r]==1){
				continue;
			}
			for(int k=l+1;k<r;k++){
				dis[l][r]=min(dis[l][r],dis[l][k]+dis[k][r]);
			}
			for(int k=l+1;k<r;k++){
				if(dis[l][r]==dis[l][k]+dis[k][r]){
					f[l][r]+=min(2ll,f[l][k]*f[k][r]);
				}
			}
			if(f[l][r]==2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--){
		if(c==11 || c==12){
			scanf("%d %lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			long long x=d/(a[2]-a[1]);
			if(x==0 || x==1 || n+1<x*2){
				printf("0\n");
			}
			else{
				printf("%lld\n",n+1-x*2);
			}
			continue;
		}
		solve();
	}
	return 0;
}
