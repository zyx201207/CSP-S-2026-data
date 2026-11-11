#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;int x,y;
int w[500005],k;
map<int,int> g[505];
vector<int> gg[505];
bool vis[500005];
int ans=1e18;
map<int,bool>zhan[500005];
void dfs(int zh,int sum,int xian,int last){
	
	if(zh==y){
		ans=min(ans,sum);
		
		return;
	}
	for(auto i:gg[xian]){
		if(vis[i]==0&&i!=zh){
			vis[i]=1;
			dfs(i,sum,xian,last);
			vis[i]=0;
		}
	}
	for(int i=1;i<=n;++i){
		if(zhan[zh][i]&&last!=i){
			dfs(zh,sum+g[i][zh]+g[xian][zh],i,xian);
		}
		
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k;      
		for(int j=1;j<=k;++j){
			int a,t;
			cin>>a>>t;
			g[i][a]=t;
			gg[i].push_back(a);
			zhan[a][j]=1;
		}
	}
	for(int i=1;i<=q;++i){
		
		cin>>x>>y;
		for(int j=1;j<=n;++j){
			if(zhan[x][j]){
				dfs(x,w[x]+w[y]+g[j][x],j,0);
			}
			
		}
		cout<<ans<<'\n';
		ans=1e18;
		for(int j=1;j<=500005;++j){
			zhan[j].clear();
			vis[i]=0;
		}
		for(int j=1;j<=505;++j){
			gg[j].clear();
			g[j].clear();
		}
	}
	return 0;
}
