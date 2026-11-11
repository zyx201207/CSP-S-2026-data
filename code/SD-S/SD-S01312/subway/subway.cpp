#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int n,m,q,k[N];
long long dis[N][N],w[M],wi,ans;
struct A{int x;long long w;};
vector<A>g[M];
signed main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e18;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i],dis[i][i]=0;
		for(int j=1,a;j<=k[i];j++){
			cin>>a>>wi;
			g[a].push_back({i,wi});
		}
	}
	for(int i=1;i<=m;i++){
		for(A x1:g[i]){
			for(A x2:g[i]){
				dis[x1.x][x2.x]=min(dis[x1.x][x2.x],x1.w+x2.w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int x,y;q;q--){
		cin>>x>>y,ans=1e18;
		for(A x1:g[x]){
			for(A x2:g[y]){
				ans=min(ans,x1.w+x2.w+dis[x1.x][x2.x]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
