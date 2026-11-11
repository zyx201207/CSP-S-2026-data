#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[20005],dis[1005][1005],w[20005],ans=1e9;
vector<pair<int,int>>e[20005];
bool v[20005];
void dfs(int x,int y,int s){
	if(x==y){
		ans=min(ans,s);
		return;
	}
	for(pair<int,int> i:e[x]){
		if(!v[i.second]){
			v[i.second]=1;
			dfs(i.second,y,s+i.first);
			v[i.second]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int a[20005],t[20005];
		for(int j=1;j<=k[i];j++)cin>>a[j]>>t[j];
		for(int j=1;j<=k[i];j++){
			for(int z=1;z<=k[i];z++){
				if(z==j)continue;
				e[a[j]].push_back({t[j]+t[z],a[z]});
			}
		}
	}
	while(q--){
		memset(v,0,sizeof(v));
		ans=1e9;
		int x,y;
		cin>>x>>y;
		v[x]=1;
		if(!dis[x][y]&&!dis[y][x])dfs(x,y,0);
		dis[x][y]=ans=dis[y][x];
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

