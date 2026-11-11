#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1.5e5;
int cc,n,m,d,q,ww[N];
namespace sa{
	int dis[505][505],vis[505][505],g[505][505];
	void main(){
		memset(dis,0x3f,sizeof dis);
		memset(g,0x3f,sizeof g);
		for(int i=1;i<=n;i++){
			int k,x,y,a,b;
			cin >> k;
			if(k==1) cin >> x >> y;
			else{
				cin >> x >> a >> y >> b;
				g[x][y]=g[y][x]=min(g[x][y],a+b);
			}
		}
		for(int i=1;i<=m;i++){
			priority_queue<pii,vector<pii>,greater<pii> > q;
			vis[i][i]=1;dis[i][i]=0;
			for(int j=1;j<=m;j++) if(g[i][j]!=0x3f3f3f3f) q.push({g[i][j],j});
			while(!q.empty()){
				pii x=q.top();q.pop();
				vis[i][x.se]=1;
				dis[i][x.se]=x.fi;
				for(int j=1;j<=m;j++) if(g[x.se][j]!=0x3f3f3f3f&&!vis[i][j]) q.push({g[x.se][j]+x.fi,j});
			}
		}
		while(q--){
			int x,y;
			cin >> x >> y;
			cout << dis[x][y]+ww[x]+ww[y] << '\n';
		}
	}
}
namespace sn2{
	int dis[2005][2005],g[2005][505];
	void main(){
		memset(dis,0x3f,sizeof dis);
		memset(g,0x3f,sizeof g);
		for(int i=1;i<=n;i++){
			int k,x,y;
			cin >> k;
			for(int j=1;j<=k;j++) cin >> x >> y,g[x][i]=y;
		}
		for(int k=1;k<=n;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dis[i][j]=dis[j][i]=min(dis[i][j],g[i][k]+g[j][k]);
		while(q--){
			int x,y;
			cin >> x >> y;
			cout << dis[x][y]+ww[x]+ww[y] << '\n';
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> cc >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> ww[i];
	if(7<=cc&&cc<=11) sa::main();
	else if(cc<=8||cc==21||cc==22) sn2::main();
	return 0;
}
/*
9 3 4 20 1
1 2 3 4
2 1 1 2 3
2 2 1 3 2
2 1 3 4 1
4 3
*/
