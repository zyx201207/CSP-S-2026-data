#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3005;
int n,p,c,t,ans1,ans;
int x[N],dp[N],f[N],dis[N],g[N][N];
void count(int now,int y,int root){
//	if(g[root][now]<y) return;
	for(int i=now+1;i<=n;i++)
		if(x[i]-x[now]<=p&&dis[i]>=y+1){
			if(dis[i]==y+1) f[i]++;
			else f[i]=1,dis[i]=y+1;
			count(i,y+1,root);
		}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
//	if(c>=3&&c<=6){
//		while(t--){
//			cin>>n>>p;
//			int ans=0;
//			memset(f,0,sizeof(f));
//			memset(g,63,sizeof(g));
//			for(int i=1;i<=n;i++) cin>>x[i];
//			for(int i=1;i<=n;i++)
//				for(int j=1;j<=n;j++)
//					if(abs(x[j]-x[i])<=p) g[i][j]=1;
//			for(int i=1;i<=n;i++) g[i][i]=0; 
//			for(int k=1;k<=n;k++)
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
////					if(!(i<=k&&k<=j)) continue;
//					if(g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
//				}
//			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++)
//					for(int k=1;k<=n;k++){
////					if(!(i<=k&&k<=j)) continue;
//					if(g[i][j]==g[i][k]+g[k][j]) f[i][j]++;
//				}
//			}
//			for(int i=1;i<=n;i++)
//				for(int j=i+1;j<=n;j++)
//					if(f[i][j]==2) ans++;
//			cout<<ans<<"\n";
//		}
//	}
	while(t--){
		cin>>n>>p;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof(f));
			memset(dis,63,sizeof(dis));
			dis[i]=0;
//			for(int k=1;k<=n;k++)
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
////					if(!(i<=k&&k<=j)) continue;
//					if(g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
//				}
//			}
			count(i,0,i);
			for(int j=1;j<=n;j++){
				if(f[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/