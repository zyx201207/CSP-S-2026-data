#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5e2+10;
const int M=1e3+10;
int c,n,m,d,q,s,T;
int k[N],w[N],a[M],t[M];
int g[M][M];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<i;j++){
			g[i][j]=INF;
			g[j][i]=INF;
		}g[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];	
		}for(int j=1;j<=k[i];j++){
			for(int _=1;_<j;_++){
				if(g[a[j]][a[_]]>t[_]+t[j]){
					g[a[j]][a[_]]=t[_]+t[j];
					g[a[_]][a[j]]=t[_]+t[j];
					//cout<<a[_]<<' '<<a[j]<<' '<<t[_]+t[j]<<'\n';
				}
			}
		}
		
	}for(int _=1;_<=m;_++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(g[i][j]>g[i][_]+g[_][j]){
					g[i][j]=g[i][_]+g[_][j];
					//cout<<i<<' '<<j<<' '<<g[i][_]+g[_][j]<<' '<<_<<'\n';
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		s=w[x]+w[y]+g[x][y];
		
		cout<<s<<'\n';
	}///////////////////////////////////////////////////
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<g[i][j]<<' ';
		}cout<<'\n';
	}*///////////////////////////////////////////////////////
	
	
	
	
	
	
	
	return 0;
	
}
