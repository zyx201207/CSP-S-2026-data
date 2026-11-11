#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long c,n,m,d,p,w[N],q;
long long s[N][N],k,a,t,S;
vector<int>v[N];
long long g[N][N];
bool sss[N];
void dfs(int u,int ti){
	if(u==n){
		return ;
	}
	for(auto x : v[u]){
		if(sss[x]==0){
			g[u][x]=min(g[u][x],ti+s[u][x]+w[x]);
			g[S][x]=min(g[S][x],ti+s[u][x]+w[x]);
			sss[x]=1;
			dfs(x,ti+s[u][x]);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			g[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			if(j>1){
				s[S][a]=t;
				s[a][S]=t;
				v[S].push_back(a);
				v[a].push_back(S);
			}
			S=a;
		}
	}
	for(int i=1;i<=n;i++){
		memset(sss,0,sizeof sss); 
		S=i;
		dfs(i,w[i]);
	}
	while(q--){
		cin>>a>>t;
		cout<<g[a][t]<<'\n';
	}
	return 0;
}
