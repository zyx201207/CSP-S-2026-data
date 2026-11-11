#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,mmin,x,y,rmin;
int dx[2]= {0,0};
int dy[2]= {1,-1};
int w[5002],k[5002],a[5002][502],t[5002][502];
int mmap[502][5002],vis[502][5002];
void dfs(int nx,int ny,int val) {
	if(ny==y) {
		mmin=min(mmin,val);
		return;
	}
	for(int i=0; i<=1; i++) {
		int fy=ny+dy[i];
		for(int j=1; j<=n; j++) {
			int fx=j;
			if(fx>=1&&fy>=1&&fx<=m&&fy<=n&&mmap[fx][fy]==1&&vis[i][j]==0) {
				vis[fx][fy]=1;
				dfs(fx,fy,val+t[nx][ny]+t[fx][fy]);
				vis[fx][fy]=0;
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	mmin=1e9;
	q=1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			mmap[i][a[i][j]]=1;
		}
	}
	while(q--) {
		cin>>x>>y;
		rmin=1e9;
		for(int i=1; i<=n; i++) {
			if(mmap[i][x]==1) {
				dfs(i,x,t[i][x]);
				rmin=min(rmin,mmin);
				mmin=1e9;
			}
		}
		cout<<rmin+w[x]+w[y];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
