#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,d,q,w[500010],dis[510][510],sum=0,ans=0;
vector<pair<int,int> >v[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto x:v[i]){
			for(auto y:v[i]){
				dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
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
		int x,y;
		cin>>x>>y;
		int mi=LONG_LONG_MAX;
		for(auto w:v[x]){
			for(auto o:v[y]){
				mi=min(mi,dis[w.first][o.first]+w.second+o.second);
			}
		}
		cout<<mi+w[x]+w[y]<<endl;
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
*/
