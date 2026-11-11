#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[1010];
struct node{
	int a,t;
}
vector<node> ve[1010];
void bfs(int u,v){
	int vis[1010];
	queue<int> q;
	q.push(u);
	vis[u]=1;
	while(q.size()){
		int t=q.front();
		q.pop();
		for(int i=0;i<ve[t].size();i++){
			if()
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int ua,ut,va,vt;
		cin>>ua>>ut>>va>>vt;
		ve[ua].push_back({va,vt});
		ve[va].push_back({ua,ut});
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<u+v;
	}
	
	return 0;
}