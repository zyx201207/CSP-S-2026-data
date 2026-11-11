#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000005];
bool vis[1000005];
int k,d[1000005];
int bfs(int u){
	int a=0,b=0;
	deque<int> q;
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	vis[u] = 1;
	d[u] = 0;
	q.push_back(u);
	for(int i=1;i<=k;i++){
		int x=q.front();
		q.pop_front();
		for(int e:g[x]){
			if(vis[e]){
				continue;
			}
			i++;
			vis[e] = 1;
			d[e] = d[x]+1;
			a = b;
			b = d[e];
			q.push_back(e);
			if(i==k){
				break;
			}
		}
	}
	return a+b;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,res=2e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			res = min(res,bfs(i));
		}
		cout<<res<<'\n';
	}
	return 0;
}
