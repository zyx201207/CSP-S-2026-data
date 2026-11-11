#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],g[505][505];
vector<long long>a[505],t[505];
vector<pair<int,int> >pos[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long to,tm;
			cin>>to>>tm;
			a[i].push_back(to);
			t[i].push_back(tm);
			pos[to].push_back({i,j});
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++){
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int sz=pos[i].size();
		for(int x=0;x<sz;x++){
			for(int y=0;y<sz;y++){
				long long xx=pos[i][x].first,yy=pos[i][y].first;
				if(xx!=yy){
					g[xx][yy]=min(g[xx][yy],t[xx][pos[i][x].second-1]+t[yy][pos[i][y].second-1]);
					g[yy][xx]=min(g[yy][xx],t[xx][pos[i][x].second-1]+t[yy][pos[i][y].second-1]);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		long long x,y,ans=1e18;
		cin>>x>>y;
		int sz1=pos[x].size(),sz2=pos[y].size();
		for(int i=0;i<sz1;i++){
			for(int j=0;j<sz2;j++){
				long long ii=pos[x][i].first,jj=pos[y][j].first;
				ans=min(ans,g[ii][jj]+t[ii][pos[x][i].second-1]+t[jj][pos[y][j].second-1]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}