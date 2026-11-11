#include<bits/stdc++.h>
#define ll long long
const int N=1e6+5;
using namespace std;
int c,t,n,k,u,v,dis[N];
bool vis[N];
vector<int> g[N];
struct node{
	int id,step;
};
void bfs(){
	queue<node> q;
	q.push({1,0});
	while(q.size()){
		node t=q.front();
		dis[t.id]=t.step;
		q.pop();
		int num=g[t.id].size();
		for(int i=0;i<num;i++){
			if(!vis[g[t.id][i]]) vis[g[t.id][i]]=1,q.push({g[t.id][i],t.step+1});
		}
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) vis[i]=0,dis[i]=1e9;
	bfs();
	sort(dis+1,dis+n+1,greater<int>());
	cout<<dis[k+1]<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
