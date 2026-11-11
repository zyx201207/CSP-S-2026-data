#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e3+10,MAX=0x3f3f3f3f3f3f3f3f;
int c,t,n,d,x[N];pii dis[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dis[i][j].fi=MAX,dis[i][j].se=0;
		for(int i=1;i<=n-1;i++){
			if(x[i+1]-x[i]<=d){
				dis[i][i+1]={1,1};
			}
		}
		for(int len=3;len<=n;len++){
			for(int l=1;l<=n-len+1;l++){
				int r=l+len-1;
				if(dis[l][r-1].fi>=MAX||dis[r-1][r].fi>=MAX){
					continue;
				}
				if(x[r]-x[l]<=d){
					dis[l][r].fi=1,dis[l][r].se=1;
					continue;
				}
				for(int k=l+1;k<r;k++){
					if(dis[l][k].fi+dis[k][r].fi<dis[l][r].fi){
						dis[l][r].fi=dis[l][k].fi+dis[k][r].fi;
						dis[l][r].se=1;
					}else if(dis[l][k].fi+dis[k][r].fi==dis[l][r].fi){
						dis[l][r].se++;
					}
				}
				if(dis[l][r].se==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}