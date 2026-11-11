#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int N=517,M=5e5+18,INF=1e17+1e16;
int c,n,m,d,q;
int w[M],k[N];
int g[N][N];//两条县见最短路 
vector<pii >b[M];
int dc(int x,int y){
	int res=INF;
	for(int i=0;i<b[x].size();i++){
		for(int j=0;j<b[y].size();j++){
			int tmp=g[b[x][i].F][b[y][j].F]+b[x][i].S+b[y][j].S;
			res=min(res,tmp);
		}
	}return res;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				g[i][j]=INF;
			}
		} 
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int t1,t2;
			cin >> t1 >> t2;
			b[t1].push_back({i,t2});
			//第t1 站经过
		}
	}
	for(int i=1;i<=m;i++){
		int len=b[i].size();
		for(int j=0;j<len;j++){
			for(int kk=0;kk<j;kk++){
				pii t1=b[i][j];
				pii t2=b[i][kk];
				if(t1.F!=t2.F){
					g[t1.F][t2.F]=min(g[t1.F][t2.F],t1.S+t2.S);
					g[t2.F][t1.F]=min(g[t1.F][t2.F],g[t2.F][t1.F]);
				}
			}
		}
	}
	for(int kk=1;kk<=n;++kk){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j&&j!=kk)
				g[i][j]=min(g[i][j],g[i][kk]+g[kk][j]);
			}
		}
	}
	//cout << g[1][2] << "((\n";
	while(q--){
		int x,y,ans=0;
		cin >> x >> y;
		ans=dc(x,y)+w[x]+w[y];
		//cout << w[x] << w[y] << "()\n";
		cout << ans << '\n';
	}
	return 0;
}
// Oct31==Dec25?
