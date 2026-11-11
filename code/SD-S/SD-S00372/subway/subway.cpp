#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
const ll inf=1e16;

ll c,n,m,d,q,w[N],k[505];
ll dis[1005][1005];
vector<int> a[505],b[505];

void solveA(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=inf;
			if(i==j)dis[i][j]=0;
		}
	}	
	for(int i=1;i<=n;i++)if(k[i]==2){
		int u=a[i][0],v=a[i][1];
		ll w=b[i][0]+b[i][1];
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(;q--;){
		int x,y;
		cin >>x>>y;
		cout <<w[x]+w[y]+dis[x][y]<<"\n";
	}
	return;		
}


void solve(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=inf;
			if(i==j)dis[i][j]=0;
		}
	}	
	for(int i=1;i<=n;i++){
		for(int ii=0;ii<k[i];ii++){
			for(int jj=0;jj<k[i];jj++){
				int u=a[i][ii],v=a[i][jj];
				ll w=b[i][ii]+b[i][jj];
				dis[u][v]=min(dis[u][v],w);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(;q--;){
		int x,y;
		cin >>x>>y;
		cout <<w[x]+w[y]+dis[x][y]<<"\n";
	}
	return;		
}

vector<int> ddd[N];

void solveB(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
			if(i==j)dis[i][j]=0;
		}
	}
	ll TT=b[1][0]*2ll;
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			int u=a[i][j];
			ddd[u].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		ll sz=ddd[i].size();
		for(int jj=0;jj<sz;jj++){
			for(int ii=0;ii<sz;ii++){
				int u=ddd[i][jj],v=ddd[i][ii];
				dis[u][v]=min(dis[u][v],TT);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(;q--;){
		int x,y;
		cin >>x>>y;
		int xsz=ddd[x].size();
		int ysz=ddd[y].size();
		ll ress=0;
		for(int ii=0;ii<xsz;ii++){
			for(int jj=0;jj<ysz;jj++){
				ress=min(ress,dis[ddd[x][ii]][ddd[y][jj]]);
			}
		}
		cout <<w[x]+w[y]+ress<<"\n";
	}
	return;			
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin >>w[i];
	}
	for(int i=1;i<=n;i++){
		cin >>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin >>x>>y;
			a[i].push_back(x);
			b[i].push_back(y);
		}
	}
	if(c>=7 && c<=11){
		solveA();
		return 0;
	}
	if(c>=16 && c<=19){
		solveB();
		return 0;
	}
	solve();
	return 0;
} 
