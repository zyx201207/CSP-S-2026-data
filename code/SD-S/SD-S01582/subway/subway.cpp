#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
	int v;
	long long w;
	friend operator < (node a,node _){
		return a.w<_.w;
	}
};
long long dfs(int u,int v,long long sum){
	if(u==v){
		return sum;
	}
	for(int i=0;i<g[u].size();i++){
		dfs(g[u][i].v,v,sum+g[u][i].w);
	}
}
int c;
int n,m,d,q;
long long w[N],t[505][25],a[505][25];
int k[505];
long long ans;
vector<node> g[N];
vector<int> o[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			o[a[i][j]].push_back(i);
			cin>>t[i][a[i][j]];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int r1=1;r1<=k[i];r1++){
				for(int r2=1;r2<=k[j];r2++){
					if(a[i][r1]==a[j][r2]){
						g[i].push_back({j,t[i][a[i][r1]]+t[j][a[j][r2]]});
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
	} 
	while(q--){
		int l,r;
		cin>>l>>r;
		for(int i=0;i<o[l].size();i++){
			for(int j=0;j<o[r].size();j++){
				int u=o[l][i];
				int v=o[r][j];
				long long ans=0x3f3f3f3f3f3f3f3f;
				ans=min(ans,dfs(u,v,0));
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
