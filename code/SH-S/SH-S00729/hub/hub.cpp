#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second

using namespace std;

const int N=1e6+10;
const int INF=1e16;

int n, k, fa[N], tot, pa[20][20], dep[N], pw[6]={1, 2, 4, 8, 16, 32};
vector<int>G[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x, int y){
	if(find(x)==find(y))return;
	tot--;
	fa[find(x)]=find(y);
	return;
}
void dfs(int u, int anc){
	dep[u]=dep[anc]+1;
	pa[u][0]=anc;
	for(int i=1;i<=4;i++){
		pa[u][i]=pa[pa[u][i-1]][i-1];
	}
	for(auto v:G[u]){
		if(v!=anc)dfs(v, u);
	}
	return;
}
int dist(int x, int y){
	int res=0;
	if(dep[x]<dep[y])swap(x, y);
	int tmp=dep[x]-dep[y];
	res+=tmp;
	for(int i=0;i<=4;i++){
		if(tmp&(1<<i))x=pa[x][i];
	}
	if(x==y)return res;
	for(int i=4;i>=0;i--){
		if(pa[x][i]!=pa[y][i]){
			x=pa[x][i], y=pa[y][i];
			res+=pw[i];
		}
	}
	return res+2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int C, T;
	cin>>C>>T;
	if(C<=3){
		while(T--){
//			cout<<"\n\nST\n";
			cin>>n>>k;
			for(int i=1;i<n;i++){
				G[i].clear();
				G[i].shrink_to_fit();
			}
			for(int i=1;i<n;i++){
				int u, v;
				cin>>u>>v;
				G[u].emplace_back(v);
				G[v].emplace_back(u);
			}
			int ans=INF;
			for(int S=0;S<(1<<n);S++){
				if(bitset<10>(S).count()!=k)continue;
				for(int i=1;i<=n;i++)fa[i]=i;
				tot=n;
				for(int i=1;i<=n;i++){
					if(S&(1<<(i-1))){
						for(auto v:G[i]){
							if(S&(1<<(v-1))){
								merge(i, v);
//								cout<<"MERGE "<<i<<' '<<v<<'\n';
							}
						}
					}
				}
//				cout<<"DONE\n";
				if(tot!=n-k+1&&tot!=n-k+2)continue;
				dfs(1, 0);
//				cout<<"DFS DONE\n";
				int mx=0;
				for(int i=1;i<=n;i++){
					if(S&(1<<(i-1)))continue;
					int mn=INF;
					for(int j=1;j<=n;j++){
						if(i==j||!(S&(1<<(j-1))))continue;
						mn=min(mn, dist(i, j));
					}
					mx=max(mx, mn);
				}
//				cout<<"CHK DONE\n";
				ans=min(ans, mx);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
打表过样例
骗分拿省一
NOIP 2026 RP++！

NOIP打完就AFO了qwq 
*/
