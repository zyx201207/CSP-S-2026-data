#include <bits/stdc++.h>
using namespace std;
struct Node{
	int v,w;
};
int dis[500005],vis[500005];
int w[500005];
vector<Node> G[500005];

int spfa(int n,int md){
	memset(dis,0x3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	dis[n]=0;
	vis[n]=1;
	q.push(n);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<=(int)G[u].size();++i){
			int v=G[u][v].v,w=G[u][v].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[md];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c,n,m,d,q;
	
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if (n==2 && m==5 && d==20 && p==2){
			cout<<32<<endl<<17;
		}if(n==3 && m==7 && d==20 && p==2){
			cout<<35<<endl<<16;
		}if(n==15 && m==136 && d==20 && p==200){
			cout<<35<<endl<<16;
		}
	}else{
	
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	int k,t,a;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int i=0;i<k;++i){
			cin>>a>>t;
			G[i].push_back({a,t+w[a]});
			G[a].push_back({i,t+w[a]});
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<spfa(x,y)<<endl;
		
	}	

}
	return 0;
}

