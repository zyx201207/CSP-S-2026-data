#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

int n,d;
const int N=2e6+5;
int a[N];
int c,t;
int dis[5005][5005];
int js[5005][5005];
int ed[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c<=10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=INF;
			}
		}
		int ans=0;
		for(int u=1;u<=n;u++){
			int r=u+1;
			for(int i=u;i<=n;i++){
				if(r<=i) r=i+1;
				while(r<=n&&a[r]-a[i]<=d){
					dis[u][r]=dis[u][i]+1;
					r++;
				}
				ed[i]=r-1;
			}
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				int res=0;
				for(int k=u+1;k<v;k++){
					if(dis[u][k]+dis[k][v]==dis[u][v]){
						res++;
					}
				}
				if(res==2){
					ans++;
		//			cout<<u<<' '<<v<<endl;
				}
			}
		}
		cout<<ans<<'\n';
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
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
