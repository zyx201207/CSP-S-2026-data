#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=310,inf=0x3f3f3f3f;
int id,t,n;
int rem[N][N];
int dist[N][N];
LL x[N],m;

void solve(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j){
				dist[i][j]=0;
				rem[i][j]=1;
			}
			else{
				dist[i][j]=inf;
				if((LL)abs(x[i]-x[j])<=m){
					dist[i][j]=1;
					rem[i][j]=1;
				}
			}
			
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					rem[i][j]=rem[i][k]*rem[k][j];
					if(rem[i][j]>2) rem[i][j]=3;
				}
				else if(dist[i][j]==dist[i][k]+dist[k][j]){
					rem[i][j]+=dist[i][k]*dist[k][j];
					if(rem[i][j]>2) rem[i][j]=3;
				}
			}
		}
	}
	
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(rem[i][j]==2)
				res++;
		}
	}
	printf("%d\n",res);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&id,&t);
	while(t--) solve();
	return 0;
}
