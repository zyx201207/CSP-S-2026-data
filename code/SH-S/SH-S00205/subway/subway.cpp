#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[509],k[509],a[509][2009],t[509][2009],tu[2009][2009];

struct Node {
	int u,v,w;
	friend bool operator< (Node a1,Node a2) {
		return a1.w>a2.w;
	}
};

int dist[2009];
bool visit[2009][2009];

void solve(int x,int y) {
	priority_queue<Node> q;
	memset(dist,0x3f3f3f,sizeof(dist));
	memset(visit,0,sizeof(visit));
	for(int i=1; i<=n; i++) {
		if(tu[x][i+m]) {
			q.push(Node {x,i+m,tu[x][i+m]});
		}
	}
	dist[x]=0;
	while(!q.empty()) {
		Node sum=q.top();
		q.pop();
		int u=sum.u,v=sum.v,w=sum.w;
		if(visit[u][v]) {
			continue;
		}
		visit[u][v]=true;
		visit[v][u]=true;
		dist[v]=min(dist[v],w);
		if(v>m) {
			for(int i=1; i<=n+m; i++) {
				if(visit[v][i]==false&&tu[v][i]) {
					q.push(Node {v,i,dist[v]+tu[v][i]});
				}
			}
			if(visit[v][y]==false&&tu[v][y]) {
				q.push(Node {v,y,dist[v]+tu[v][y]});
			}
		}
	}
	cout<<dist[y]<<endl;
	return;
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
			tu[a[i][j]][m+i]=w[a[i][j]]+t[i][j];
			tu[m+i][a[i][j]]=w[a[i][j]]+t[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			for(int k=1; k<=m; k++) {
				if(tu[k][m+i]&&tu[k][m+j]) {
					int t=tu[k][m+i]+tu[k][m+j]-2*w[k];
					if(tu[m+i][m+j]) {
						tu[m+i][m+j]=min(tu[m+i][m+j],t);
						tu[m+j][m+i]=min(tu[m+j][m+i],t);
					} else {
						tu[m+i][m+j]=t;
						tu[m+j][m+i]=t;
					}
				}
			}
		}
	}
	for(int i=1; i<=q; i++) {
		int x=0,y=0;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}

