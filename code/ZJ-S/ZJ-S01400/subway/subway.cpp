#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=605;
int c,n,m,d,q;
int w[N];
int v[N];
int dist[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int cnt=m;
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			v[j]=++cnt;
			dist[x][cnt]=dist[cnt][x]=t;
		}
		for(int j=2;j<=k;j++){
			dist[v[j-1]][v[j]]=0;
		}
	}
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
