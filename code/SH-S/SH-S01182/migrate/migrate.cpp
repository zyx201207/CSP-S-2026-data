#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
int tid,_,n,d,ans,x[N],dis[N][N],cnt[N][N];
void solve1(){
	while(_--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=0x3f3f3f3f;cnt[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(abs(x[j]-x[i])<=d)
					dis[i][j]=1;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][j]==dis[i][k]+dis[k][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						cnt[i][j]=cnt[i][k]*cnt[k][j];
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2) ans++;
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>tid>>_;
	if(tid<=6){
		solve1();
	}
	return 0;
}
