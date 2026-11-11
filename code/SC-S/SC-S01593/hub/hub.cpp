#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
const int N=1e3+5;
int dis[N][N],a[N];
bool check(){
	int cnt=k;
	for(int i=1;i<=k;i++){
		for(int j=i;j<=k;j++){
			if(dis[a[i]][a[j]]==1) cnt--;
		}
	}
	return cnt<=2;
}
void solve(){
	memset(dis,0x3f3f,sizeof(dis));
	
	for(int i=1,u,v;i<n;i++){
		scanf("%lld%lld",&u,&v);
		dis[u][v]=dis[v][u]=1;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	int ans=1e18;
	while(next_permutation(a+1,a+1+n)){
		if(!check()) continue;
		int sum=0,minn;
		for(int i=1;i<=n;i++){
			minn=1e18;
			for(int j=1;j<=k;j++){
				minn=min(dis[i][a[j]],minn);
			}
			sum=max(sum,minn);
		}
		ans=min(ans,sum);		
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		if(n<=100)
		solve();
		else{
			for(int i=1,u,v;i<n;i++)
				scanf("%lld%lld",&u,&v);
			printf("%lld\n",n/k);
		}
	}
	return 0;
}