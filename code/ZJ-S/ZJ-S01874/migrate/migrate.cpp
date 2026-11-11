#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
const int INF=1e18;
int x[N],dis[N][N],edge[N][N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
			edge[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(x[i]-x[j])<=d){
				edge[j][i]=1;
				dis[j][i]=1;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]==INF)continue;
			for(int j=1;j<=n;j++){
				if(dis[k][j]==INF)continue;
				if(edge[i][j]==0){
					edge[i][j]=edge[j][i]=edge[i][k]+edge[k][j];
					dis[i][j]=1;
				}
				else if(edge[i][j]>edge[i][k]+edge[k][j]){
					dis[i][j]=dis[i][k]*dis[k][j];
					edge[i][j]=edge[j][i]=edge[i][j]+edge[k][j];
				}else if(edge[i][j]==edge[i][k]+edge[k][j]){
					dis[i][j]++;
				}
			}
		}
	}int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(dis[i][j]==2)ans++;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}