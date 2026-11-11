#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],ans;
long long vis[500005];
bool used[505];
vector<int>e[505];
vector<int>xx[500005];
map<int,int>mp[505];
void dfs(int x,int y){
	if(x==y)return;
	for(int i = 0 ; i < xx[x].size();i++){
		int x1=xx[x][i];
		if(used[x1])continue;
		used[x1]=1;
		for(int j = 0 ; j < e[x1].size();j++){
			int v=e[x1][j],w=vis[x]+mp[x1][x]+mp[x1][v];
			if(vis[v]>w){
				vis[v]=w;
				dfs(v,y);
			}
		}
		used[x1]=0;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)cin >> w[i];
	for(int i = 1 ; i <= n ; i++){
		int k;
		cin >> k ;
		for(int j= 1; j <= k ; j++){
			int a,t;
			cin >> a >> t ;
			e[i].push_back(a);
			xx[a].push_back(i);
			mp[i][a]=t;
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		memset(vis,0x3f,sizeof(vis));
		memset(used,0,sizeof(used));
		vis[x]=w[x];
		dfs(x,y);
		cout << vis[y]+w[y]<<endl;
	}
	return 0;
}
