#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=5e5+10;
vector<pair<int,int> > vt[N];
int a[N];
int dis[1010][1010];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=1e18;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int u=0,p=0;
	int k;
	for(int i=1;i<=n;i++){
		cin >>k;
		for(int j=1;j<=k;j++){
			cin >>u>>p;
			vt[u].push_back({i,p});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:vt[i]){
			for(auto k:vt[i]){
				if(j.first!=k.first){
					dis[j.first][k.first]=dis[k.first][j.first]=min(dis[k.first][j.first],k.second+j.second);
				}
			}
		}
	}
	floyd();
	//cout <<dis[1][1]<<endl;
	while(q--){
		int u,v;
		cin >>u>>v;
		int ans=1e18;
		for(auto i:vt[u]){
			for(auto j:vt[v]){
				ans=min(ans,dis[i.first][j.first]+a[u]+a[v]+i.second+j.second);
			}
		}
		cout <<ans<<'\n';
	}
	return 0;
}

