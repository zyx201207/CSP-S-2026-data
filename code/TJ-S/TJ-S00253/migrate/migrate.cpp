#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<cstring> 
#define int long long 
using namespace std;
const int maxn=5e3+5;
/*
maxn
long long  signed 
多测清空 
freopen不要注释 
*/
int T,n,d,x[maxn],dis[maxn][maxn],num[maxn][maxn],ans,c;
void solve(){
	ans=0;
	scanf("%lld%lld",&n,&d);
	memset(dis,0x3f3f,sizeof(dis));
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				dis[i][j]=1;
				num[i][j]=1;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||i==k||j==k) continue;
				if(dis[i][k]+dis[k][j]==dis[i][j]){
					num[i][j]+=num[i][k]*num[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(num[i][j]==2) ans++;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		solve();
	}
	return 0;
} 
