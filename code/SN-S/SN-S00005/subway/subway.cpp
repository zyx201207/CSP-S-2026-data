//SN-S00005 BZOI2729 Cl_baseRF 
#include<bits/stdc++.h>
using namespace std;
long long wk[500050],k[550];
long long t[550][550];
vector<long long>sbw[5500];
bool vis[500050];
struct node{
	long long v,rt;
};
vector<node>G[550];
long long dst[550];
void dfs(long long x,long long y,long long rte,long long ans){
	if(x==y){
		ans+=t[y][rte];
		dst[y] = min(dst[y],ans);
		return;
	}
	for(int i = 0;i<G[x].size();i++){
		int v = G[x][i].v,rt = G[x][i].rt;
		if(vis[v])continue;

		if(rt!=rte){
			dfs(v,y,rt,ans+t[x][rt]+t[x][rte]);
		}
		else dfs(v,y,rte,ans);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i = 1;i<=m;i++){
		cin>>wk[i];
	}
	for(long long i = 1;i<=n;i++){
		cin>>k[i];
		int a;
		for(int j = 1;j<=k[i];j++){
			int a1;
			cin>>a1;
			sbw[a1].push_back(i);
			cin>>t[a1][i];
			if(j>=2){
				G[a].push_back({a1,i});
				a = a1;
			}
			else a = a1;
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		for(long long i = 1;i<=m;i++){
			dst[i] = 1e17+7;
		}
		int x,y;
		cin>>x>>y;
		for(int i = 0;i<sbw[x].size();i++){
			dfs(x,y,sbw[x][i],t[x][sbw[x][i]]);
		}
		dst[y]+=wk[x];
		dst[y]+=wk[y];
		cout<<dst[y]<<endl;
	}
	return 0;
}
