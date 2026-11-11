#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=510,M=500100;
int C,n,m,d,q,w[M],len[N];
vector<pair<int,int>>belong[M];
long long dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			int id,cost;
			cin>>id>>cost;
			belong[id].emplace_back(i,cost);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0ll;
	for(int i=1;i<=m;i++){
		for(pair<int,int> u:belong[i]){
			for(pair<int,int> v:belong[i]){
				dis[u.first][v.first]=
					min(dis[u.first][v.first],(long long)u.second+v.second);
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
	for(int I=1;I<=q;I++){
		int U,V;
		cin>>U>>V;
		long long ans=dis[0][0];
		for(pair<int,int> u:belong[U]){
			for(pair<int,int> v:belong[V]){
				ans=min(ans,w[U]+w[V]+u.second+v.second+dis[u.first][v.first]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}