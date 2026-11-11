#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305,maxn=2e6+5,inf=2e18+2;
int x[maxn];
int dis[N][N],dp[N][N];
int n,d;
int dfs(int x,int y,int sum){
//	cout<<x<<" "<<y<<" "<<sum<<endl;
	if(x==y){
		if(!sum) return 1;
		return 0;
	}
	if(!sum) return 0;
	int now=0;
	for(int i=x+1;i<=y;i++){
		if(dis[x][i]<=d) now+=dfs(i,y,sum-1);
		else break;
	}
	return now;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=inf;
			}
		}
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int i=1;i<=n;i++){
			int lst=i;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d) break;
				if(x[j]-x[lst]>d) lst=j-1;
				dis[i][j]=dis[i][lst]+1;
			}
		}
		if(c<=2){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dis[i][j]==1) continue;
					if(dis[i][j]==inf) break;
					int sum=dfs(i,j,dis[i][j]);
	//				cout<<i<<" "<<j<<" "<<sum<<endl;
					if(sum==2) ans++;
				}
			}
			cout<<ans<<endl;
			continue;	
		}
		if(c<=6){
			int ans=0;
			for(int d=2;d<=n;d++){
				for(int l=1;l<=n-d+1;l++){
					int r=l+d-1;
					if(dis[l][r]==1) dp[l][r]=1;
					if(dis[l][r]==1||dis[l][r]==inf) continue;
					int sum=1,lst=r;
					for(int i=l+1;i<=r-1;i++){
						if(dis[l][i]>1){
							lst=i;
							break;
						}
						sum+=dp[l][i]*dp[i][r];
//						if(l==1&&r==4) cout<<i<<" "<<sum<<endl;
					}
//					if(l==1&&r==4) cout<<sum<<endl;
					for(int i=r-1;i>=lst;i--){
						if(dis[i][r]>1) break;
						if(dp[l][i]>1) sum+=dp[l][i]*dp[i][r];
//						if(l==1&&r==4) cout<<i<<" "<<sum<<endl;
					}
//					if(l==1&&r==4) cout<<sum<<endl;
					dp[l][r]=sum;
					if(sum==2){
//						cout<<l<<" "<<r<<endl;
						ans++; 
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c<=12){
			int D=x[2]-x[1];
			if(d<2*D) cout<<"0\n";
			else cout<<n*(n-1)/2<<'\n';
		} 
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 10
-10 0 8 17 30
0

0 1
5 5
0 5 7 10 11
2
0£ºl-rÖÐÓÐ>dµÄ
_ _
o,o
 ^
*/
