#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
#define eb emplace_back
#define mkp make_pair
using namespace std;
const int N=5001+1;
int c,t,n,d,a[N],dis[N][N],cnt[N][N];
vector<pll> g[N];
inline void floyd(){
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==k||j==k) continue;
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					cnt[i][j]=0;
				}
				if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=5000){
			memset(dis,0x3f,sizeof dis);
			memset(cnt,0,sizeof cnt);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d) continue;
					g[i].eb(mkp(j,1));
					dis[i][j]=1;
				}
			}
			floyd();
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans+=(cnt[i][j]==2);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
*/
