#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int NN=2e3+10;
const int NNN=5e2+10;
int c,n,m,dd,q,w[N],wt,ans,d[NN][NN],kk[N],a,t,l,r,dis[NNN][NNN];
vector<pair<int,int> >g[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(n+m<=600){
		wt=n+m;
		for(int i=1;i<=wt;i++){
			for(int j=1;j<=wt;j++){
				d[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>kk[i];
			for(int j=1;j<=kk[i];j++){
				cin>>a>>t;
				d[i+m][a]=d[a][i+m]=t;
			}
		}
		for(int k=1;k<=wt;k++){
			for(int i=1;i<=wt;i++){
				for(int j=1;j<=wt;j++){
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
		while(q--){
			cin>>l>>r;
			cout<<d[l][r]+w[l]+w[r]<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>kk[i];
		for(int j=1;j<=kk[i];j++){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:g[i]){
			for(auto k:g[i]){
				if(j.first==k.first){
					dis[j.first][k.first]=0;
				}else{
					dis[j.first][k.first]=dis[k.first][j.first]=min(dis[j.first][k.first],j.second+k.second);
				}
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
	while(q--){
		cin>>l>>r;
		ans=1e18;
		for(auto j:g[l]){
			for(auto k:g[r]){
				ans=min(ans,j.second+k.second+dis[j.first][k.first]);
			}
		}
		cout<<ans+w[l]+w[r]<<"\n";
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
