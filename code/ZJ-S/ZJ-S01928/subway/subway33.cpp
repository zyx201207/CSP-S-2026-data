#include<bits/stdc++.h>
using namespace std;
#define int long long

//const int NN=607,N=207,M=407,Q=207;
const int NN=1007,N=507,M=5e5+7,Q=207;
const int INF=1e17;
//const int INF=1e2;
int c,n,m,d,q;
int dis[NN][NN];
int w[M];

struct node{
	int v,w;
};
vector<node> e[M];

//void print(){
//	cerr << "---\n";
//	for(int i=1;i<=m+n;i++){
//		for(int j=1;j<=m+n;j++){
//			cerr << dis[i][j] << '\t';
//		}
//		cerr << '\n';
//	}
//}

void baoli(){
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin >> aa >> tt;
			dis[aa][m+i]=tt;
			dis[m+i][aa]=tt;
		}
	}
	
	//floyd
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j]; 
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+dis[x][y] << '\n';
	}
}

void solveA(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		int aa,ta,bb,tb;
		cin >> aa >> ta;
		if(k==1)	continue;
		cin >> bb >> tb;
		dis[aa][bb]=ta+tb;
		dis[bb][aa]=ta+tb;
	}
	
	//floyd
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j]; 
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+dis[x][y] << '\n';
	}
}

void solveB(){
	
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin >> aa >> tt;
			e[aa].push_back({m+i,tt});
			e[m+i].push_back({aa,tt});
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		queue<pair<int,int> > q;
		vector<bool> vis(n+m+1);
		q.push({x,0});
		vis[x]=1;
		int ans=-1;
		while(!q.empty()){
			int u=q.front().first,step=q.front().second;
			q.pop();
			if(u==y){
				ans=step;
				break;
			}
			for(node p:e[u]){
				int v=p.v,w=p.w;
				if(vis[v])	continue;
				vis[v]=1;
				q.push({v,step+w});
			}
		}
		cout << w[x]+w[y]+ans << '\n';
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway2.err","w",stderr);
	
	cin >> c >> n >> m >> d >> q;
	if(n+m<=605){
		baoli();
	}
	else if(n+m<=1505){
		solveA();
	}
	else{
		solveB();
	}
}
