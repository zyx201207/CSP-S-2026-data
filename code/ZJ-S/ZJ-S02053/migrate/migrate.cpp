#include <bits/stdc++.h>
#define int long long
#define P pair<int,int>
using namespace std;
const int N=5005;
int c,T,n,d,x[N],dis[N][N],ans,cnt[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(x[j]-x[i]<=d) dis[i][j]=dis[j][i]=1;
			}
		}
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						cnt[i][j]=1;
					}
					else if(dis[i][j]==dis[i][k]+dis[k][j]) cnt[i][j]++;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
