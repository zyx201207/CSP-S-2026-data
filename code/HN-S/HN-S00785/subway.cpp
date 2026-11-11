#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
vector<pair<int,long long>> v[500005];
long long dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto j:v[i]){
			for(auto k:v[i]){
				dis[j.first][k.first]=min(dis[j.first][k.first],j.second+k.second);
				dis[k.first][j.first]=min(dis[k.first][j.first],j.second+k.second);
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
	//cout<<dis[1][2]<<'\n';
	while(q--){
		int a,b;cin>>a>>b;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto i:v[a]){
			for(auto j:v[b]){
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[a]+w[b]<<'\n';
	}
	return 0;
}
