#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int inf=1e18+7;
int c,T,n,k,ans[15],fa[15],tot,res;
bool vis[15],vis1[15],vis2[15];
vector<int> v[15];
void dfs1(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();++i){
		int u=v[x][i];
		if(!vis[u]&&vis2[u]){
			dfs1(u);
		}
	}
}
int bfs(int x){
	if(vis[x]) return 0;
	queue<pair<int,int> > q;
	q.push({x,0});
	while(!q.empty()){
		pair<int,int> P=q.front();
		q.pop();
		int u=P.first;
		vis1[u]=0;
		for(int i=0;i<v[u].size();++i){
			int w=v[u][i];
			if(vis1[w]) continue;
			if(vis2[w]) return P.second+1;
			q.push({w,P.second+1});
		}
	}
}
void check(){
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=tot;++i) vis2[ans[i]]=1;//cout<<ans[i]<<' ';
	//cout<<endl;
	int cnt=0;
	for(int i=1;i<=tot;++i){
		if(!vis[ans[i]]){
			dfs1(ans[i]);
			cnt++;
		}
	}
//	cout<<cnt<<endl;
	if(cnt<=2){
		int ret=0;
		for(int i=1;i<=n;++i){
			memset(vis1,0,sizeof(vis1));
			ret=max(ret,bfs(i));
		}
		res=min(res,ret);
	}
}
void dfs(int x,int t){
	if(t==k){
		check();
		return ;
	}
	if(x==n+1) return ;
	ans[++tot]=x;
	dfs(x+1,t+1);
	tot--;
	dfs(x+1,t);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		tot=0;
		res=inf;
		cin>>n>>k;
		for(int i=1;i<=n;++i) v[i].clear();
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		cout<<res<<endl;
	}
	return 0;
}

