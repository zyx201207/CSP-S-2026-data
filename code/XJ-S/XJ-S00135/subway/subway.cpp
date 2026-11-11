#include<bits/stdc++.h>
using namespace std;
struct node{
	int y;
	long long w;
};
int c,n,m,d,q;
long long w[500005];
vector<node>gg[500005];
long long g[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int x;
			long long w;
			cin>>x>>w;
			gg[x].push_back({i,w});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			g[i][j]=1e18;
		}
		g[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<gg[i].size();++j){
			for(int k=j+1;k<gg[i].size();++k){
				g[gg[i][j].y][gg[i][k].y]=gg[i][j].w+gg[i][k].w;
				g[gg[i][k].y][gg[i][j].y]=gg[i][j].w+gg[i][k].w;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=1;k<=n;++k){
				g[j][i]=g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		long long mn=1e18;
		cin>>x>>y;
		for(int j=0;j<gg[x].size();++j){
			for(int k=0;k<gg[y].size();++k){
				mn=min(mn,gg[x][j].w+gg[y][k].w+g[gg[x][j].y][gg[y][k].y]);
			}
		}
		cout<<mn+w[x]+w[y]<<'\n';
	}
	return 0;
}
