#include<iostream>
#include<queue>
#include<map>
using namespace std;
typedef pair< int,pair<int,int> > pii; 
int w[500025],n,m;
map<int,int> ma[505];
vector< pair<int,int> > qs[500025],g[20010][505];
int cr[500025][25],top[500025];
long long ans=1000000000000000009;
bool v[20010][505];
void dfs(int x,int ww,int e,long long sum){
	if(x==e){
		ans=min(ans,sum+ma[ww][e]+w[e]);
		return ;
	}
	for(auto xx:g[x][ww]){
		if(v[xx.first][xx.second]==1) continue;
		v[xx.first][xx.second]=1;
		if(ww!=xx.second) dfs(xx.first,xx.second,e,sum+ma[ww][x]+ma[xx.second][xx.first]);
		else dfs(xx.first,xx.second,e,sum);
		v[xx.first][xx.second]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int q;
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int l=0;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			ma[i][x]=t;
			top[x]++;
			cr[x][top[x]]=i;
			if(l!=0){
				g[x][i].push_back({l,i});
				g[l][i].push_back({x,i});
			}
			l=x;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=top[i];j++){
			for(int k=1;k<=top[i];k++){
				if(j==k) continue;
				g[i][cr[i][j]].push_back({i,cr[i][k]});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1000000000000000009;
		for(int i=1;i<=top[x];i++){
			v[x][cr[x][i]]=1;
			dfs(x,cr[x][i],y,w[x]+ma[cr[x][i]][x]);
			v[x][cr[x][i]]=0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
