#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=505;
const int M=5e5+5;
int n,m,d,q;
vector<pair<int,int> > v[M],g[N];
ll dis[N][N];
int w[M];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int CC;
	cin>>CC>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int cnt;
		cin>>cnt;
		int x,y;
		for(int j=1;j<=cnt;j++){
			cin>>x>>y;
			v[x].push_back({i,y});
			g[i].push_back({x,y});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(pair<int,int> t:g[i]){
			for(pair<int,int> to:v[t.first]){
				dis[i][to.first]=min(dis[i][to.first],(ll)t.second+to.second);
//				dis[to.first][i]=min(dis[to.first][i],dis[i][to.first]);
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
	int x,y;
	while(q--){
		cin>>x>>y;
		ll ans=1e18;
		for(pair<int,int> t1:v[x]){
			for(pair<int,int> t2:v[y]){
				ans=min(ans,dis[t1.first][t2.first]+w[x]+w[y]+t1.second+t2.second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
