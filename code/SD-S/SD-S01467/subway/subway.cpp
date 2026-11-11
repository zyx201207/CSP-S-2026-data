#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
vector<int>g[N];
int c,n,m,d,q,u,v,w,k,a[N],t[N];
signed bfs(int x,int y){
	queue<int>p;
	p.push(x);
	t[x]=1;
	while(!p.empty()){
		int nw=p.front();
		p.pop();
		for(auto &o:g[nw]){
			if(!t[o]){
				t[o]=t[nw]+1;
			}
			if(o==y){
				return t[o];
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>u>>w;
		for(int j=2;j<=k;j++){
			cin>>v>>w;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<bfs(x,y);
	}
	return 0;
}
