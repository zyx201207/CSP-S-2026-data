#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5009;
int c,t;
int x[N];
int dis[N][N];
int cnt[N][N];
bool can[N][N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e9,cnt[i][j]=0,can[i][j]=0;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
			if(i==j)continue;
			if(abs(x[i]-x[j])<=d){
				can[i][j]=1;
				dis[i][j]=1;
				cnt[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					can[i][j]|=(can[i][k]&can[k][j]);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(!can[i][j])continue;
					if(i==k||j==k)continue;
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}else if(dis[i][j]==dis[i][k]+dis[k][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans+=(cnt[i][j]==2);
		cout<<ans<<endl;
	}
}
