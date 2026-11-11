#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,d,q,dis[509][509],w[500009];
vector<pair<int,int> > sta[500009];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
//	cout<<"checkp1\n";
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;cin>>k;
		while(k--){
			int x,y;cin>>x>>y;
			for(pair<int,int> u:sta[x]){
				dis[u.first][i]=min(dis[u.first][i],u.second+y);
				dis[i][u.first]=min(dis[i][u.first],u.second+y);
			}
			sta[x].push_back({i,y});
//			lin[i].push_back({})
		}
	}
//	cout<<"checkp2\n";
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
//	cout<<"checkp3\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=1e18;
		for(pair<int,int> u:sta[x]){
			for(pair<int,int> v:sta[y]){
				ans=min(ans,w[x]+w[y]+v.second+u.second+dis[u.first][v.first]);
			}
		}
		cout<<ans<<"\n";
	}
//	cout<<"checkp4\n";
	return 0;
}
