#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,k,ans=1e18;
vector<int>g[1000010];
int a[10010],box[10010];

int find(int a){
	if(box[a]==a) return a;
	return box[a]=find(box[a]);
}

void merge(int a,int b){
	int x=find(a),y=find(b);
	box[x]=y;
}

int bfs(){
	int maxn=0;
	for(int s=1;s<=n;s++){
		if(a[s]) continue;
		int dis[110];
		memset(dis,0,sizeof(dis));
		queue<int>q;
		q.push(s);
		while(q.size()){
			int u=q.front();
			q.pop();
			if(a[u]){
				//cout<<dis[u]<<' ';
				maxn=max(maxn,dis[u]);
				break;
			}
			for(auto v:g[u]){
				if(dis[v] || v==s) continue;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	//cout<<endl;
	return maxn;
}

void dfs(int step,int used){
	if(step>n){
		if(used!=k) return;
		for(int i=1;i<=n;i++) box[i]=i;
		for(int i=1;i<=n;i++){
			if(!a[i]) continue;
			for(int j=0;j<g[i].size();j++){
				int v=g[i][j];
				if(a[v]){
					merge(i,v);
				}
			}
		}
		map<int,int>mp;
		for(int i=1;i<=n;i++){
			if(a[i]) mp[find(i)]++;
		}
		if(mp.size()>2) return;
		int dis=bfs();
		if(ans>dis){
			ans=dis;
			//for(int i=1;i<=n;i++) cout<<a[i]<<' ';
			//cout<<endl<<dis<<endl;
		}
		return;
	}
	dfs(step+1,used);
	a[step]=1;
	dfs(step+1,used+1);
	a[step]=0;
}

void calc(){
	cin>>n>>k;
	ans=1e18;
	for(int i=1;i<=100;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		calc();
	}
	return 0;
}

