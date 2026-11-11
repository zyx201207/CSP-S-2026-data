#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y1 y_1
#define f1 first
#define s2 second
const int M=3e3+10;
const int N=2e5+10;
const int INF=1e18;
int n,m,y,q;
int w[N],dist[N],d[M][M],c[M][M];
int k[M],a[M][M],t[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int C;
	cin>>C>>n>>m>>y>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2) f=false;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			d[a[i][j]][i]=d[i][a[i][j]]=t[i][j]+w[i];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]!=INF&&d[k][j]!=INF){
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<d[x][y]<<'\n';
	}
	return 0;
}