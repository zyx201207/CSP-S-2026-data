#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vp vector<pii>
using namespace std;
constexpr int N=500500+10,M=500+10,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,val[N];
vp G[N];
vi nd[N];
map<int,int> mp[M];
int dis[M][M],ds[N];
bool vis[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>val[i];
	for(int i=1,len;i<=n;i++){
		cin>>len;
		for(int j=1,a,t;j<=len;j++){
			cin>>a>>t;
			nd[a].push_back(i);
			mp[i][a]=t;
			G[a].push_back({m+i,t});
			G[m+i].push_back({a,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(auto j:G[i]){
			for(auto k:G[i]){
				if(j.first==k.first) continue;
				int x=j.first,y=k.first;
				dis[x-m][y-m]=dis[y-m][x-m]=min(dis[x-m][y-m],j.second+k.second);
			}
		}
	} 
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int x,y,ans=inf; cin>>x>>y;
		for(int i:nd[x]){
			for(int j:nd[y]) ans=min(ans,dis[i][j]+mp[i][x]+mp[j][y]);
		}
		cout<<ans+val[x]+val[y]<<"\n";
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
