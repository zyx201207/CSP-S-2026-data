#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,p,a[500010],dits[500010],vis[500010];
vector<pair<int,int>> du[500010];
void f(int x,int fa){
	vis[x]=1;
	for(int i=0;i<du[x].size();i++){
		int v=du[x][i].first;
		if(v==fa||vis[v])continue;
		if(dits[v]>dits[x]+du[x][i].second){
			dits[v]=dits[x]+du[x][i].second;
			f(v,x);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			int k,u,v,t1,t2;
			cin>>k;
			if(k==1){
				cin>>u>>t1;
				continue;
			}
			cin>>u>>t1>>v>>t2;
			du[u].push_back({v,t1+t2});
			du[v].push_back({u,t1+t2});
		}
		while(p--){
			memset(dits,0x3f3f3f3f,sizeof(dits));
			memset(vis,0,sizeof(vis));
			int x,y;
			cin>>x>>y;
			dits[x]=0;
			f(x,x);
			cout<<dits[y]+a[x]+a[y]<<"\n";
		}
	}
	return 0;
}
