#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int w[500005];
ll dist[505][505];
vector<pair<int,int>>sub[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	fill(dist[1],dist[500]+501,LLONG_MAX);
	for(int i=1;i<=n;i++)
		dist[i][i]=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			for(pair<int,int> cur:sub[a])
				dist[i][cur.first]=dist[cur.first][i]=dist[cur.first][i]>t+cur.second?t+cur.second:dist[cur.first][i];
			sub[a].push_back(make_pair(i,t));
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k]==LLONG_MAX||dist[k][j]==LLONG_MAX)continue;
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll ans=LLONG_MAX;
		for(pair<int,int> X:sub[x]){
			for(pair<int,int> Y:sub[y]){
				ans=min(ans,dist[X.first][Y.first]+X.second+Y.second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}