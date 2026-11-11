#include <bits/stdc++.h>
using namespace std;
#define int long long
#define re register
const int N=5e2+1,M=5e5+1;
int c,n,m,d,q,w[M],ans,st,ed,tt,dis[N][N];
map<pair<int,int>,int> mp;
vector<int> a[M],col[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(re int i=1;i<=m;i++) cin>>w[i];
	for(re int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			if(u==v) dis[u][v]=0;
			else dis[u][v]=1e18;
		}
	}
	for(re int i=1,k;i<=n;i++){
		cin>>k;
		a[i].push_back(k);
		for(re int j=1,A,T;j<=k;j++){
			cin>>A>>T;
			a[i].push_back(A);
			for(int p=0;p<col[A].size();p++){
				dis[i][col[A][p]]=min(dis[i][col[A][p]],mp[{col[A][p],A}]+T);
				dis[col[A][p]][i]=dis[i][col[A][p]];
			}
			col[A].push_back(i);
			mp[{i,A}]=T;
		}
	}
	for(re int k=1;k<=n;k++){
		for(re int i=1;i<=n;i++){
			for(re int j=1;j<=n;j++){
				if(i!=j&&j!=k&&i!=k){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
				}
			}
		}
	}
	while(q--){
		cin>>st>>ed;
		ans=LLONG_MAX;
		for(re int i=0;i<col[st].size();i++){
			int u=col[st][i];
			for(re int j=0;j<col[ed].size();j++){
				int v=col[ed][j];
				ans=min(ans,dis[u][v]+w[st]+w[ed]+mp[{u,st}]+mp[{v,ed}]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
