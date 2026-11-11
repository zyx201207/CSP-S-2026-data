#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305;
int c,t;
int n,m,a[N],dis[N][N],cnt[N][N],ans;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e9,cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=m){
					dis[i][j]=0,cnt[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
//					cout<<dis[i][k]<<" "<<dis[k][j]<<" "<<dis[i][j]<<"\n";
					if(dis[i][j]>dis[i][k]+dis[k][j]+1){
						dis[i][j]=dis[i][k]+dis[k][j]+1;
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}else if(dis[i][j]==dis[i][k]+dis[k][j]+1){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<dis[i][j]<<" "<<cnt[i][j]<<"\n";
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}