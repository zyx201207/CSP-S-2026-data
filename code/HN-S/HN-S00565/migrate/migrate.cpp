#include <bits/stdc++.h>
using namespace std;

long long c,t,n,d;
long long a[1000],f[1000][1000],dist[1000][1000];
long long ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		memset(f,0,sizeof(f));
		memset(dist,0x3f,sizeof(dist));
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					dist[i][j]=1;
					f[i][j]=1;
				}
			} 
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j||j==k||k==i)continue;
					if(dist[i][k]+dist[k][j]<dist[i][j]){
						dist[i][j]=dist[i][k]+dist[k][j];
						f[i][j]=f[i][k]*f[k][j];
					}else if(dist[i][k]+dist[k][j]==dist[i][j]){
						f[i][j]+=f[i][k]*f[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f[i][j]==2){
					dist[i][j]=1;
					ans++;
				}
			} 
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
