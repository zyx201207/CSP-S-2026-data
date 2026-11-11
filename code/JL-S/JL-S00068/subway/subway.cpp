#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int M=5e5+10;
const int N=510;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],x,y,vis[M];
struct node{
	int x,tim,op;
};
struct edge{
	int x,op;
};
queue<node> que;
vector<edge> G[M];
int fin(int op,int x){
	for(int i=1;i<=k[op];i++){
		if(a[op][i]==x){
			return i;
		}
	}
}
void bfs(){
	while(!que.empty()){
		auto x=que.front();
		que.pop();
		if(x.x==y){
			// cout<<x.op<<endl;
			cout<<x.tim+w[y]+t[x.op][fin(x.op,y)]<<endl;
			// cout<<w[y]<<" "<<x.op<<" "<<x.tim<<endl;
			return;
		}
		for(auto v:G[x.x]){
			if(vis[v.x]==0){
				// vis[v.x]=1;
				// cout<<x.op<<" "<<x.x<<" "<<x.tim<<" "<<v.op<<" "<<v.x<<endl;
				if(x.op!=v.op){
					que.push({v.x,x.tim+t[x.op][fin(x.op,x.x)]+t[v.op][fin(v.op,x.x)],v.op});
					// cout<<t[x.op][fin(x.op,x.x)]<<" "<<t[v.op][fin(v.op,x.x)]<<endl;
				}
				else que.push({v.x,x.tim,x.op});
			}
		}
		for(int i=1;i<=n;i++){
			if(i==x.op)continue;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x.x){
					que.push({x.x,x.tim+t[x.op][fin(x.op,x.x)]+t[i][fin(i,x.x)],i});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			for(int l=1;l<j;l++){
				G[a[i][l]].push_back({a[i][j],i});
				G[a[i][j]].push_back({a[i][l],i});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		while(!que.empty()){
			que.pop();
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					que.push({x,w[x]+t[i][j],i});
					// cout<<i<<" "<<j<<endl;
					vis[x]=1;
				}
			}
		}
		// que.push_back({x,w[x]});
		bfs();
	}
}

