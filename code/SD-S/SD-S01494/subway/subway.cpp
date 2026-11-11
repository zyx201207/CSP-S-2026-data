#include<bits/stdc++.h>
using namespace std;
long long x,z,y,c,n,m,d,q,w[2007],kk,tt[20007][507],dist[507][507];
bool adj[2007][507];
vector<int>com[2007];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>kk;
		for(int j=1; j<=kk; j++) {
			cin>>x>>z;
			tt[x][i]=z;
			adj[x][i]=1;
			com[x].push_back(i);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i!=j)dist[i][j]=dist[j][i]=1e9;
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				if(adj[i][j]==1&&adj[i][k]==1) {
					dist[j][k]=dist[k][j]=min(dist[j][k],tt[i][j]+tt[i][k]);
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=n; k++) {
			for(int j=1; j<=n; j++) {
				if(i!=k&&k!=j&&i!=j) {
					if(dist[i][k]+dist[k][j]<dist[i][j]) {
						dist[i][j]=dist[i][k]+dist[k][j];
					}
				}
			}
		}
	}

	for(int i=1; i<=q; i++) {
		cin>>x>>y;
		long long minn=1e9;
		for(int j=0; j<com[x].size(); j++) {
			for(int k=0; k<com[y].size(); k++) {
				int aaa=com[x][j],bbb=com[y][k];
				if(dist[aaa][bbb]+tt[x][aaa]+tt[y][bbb]<minn) {
					minn=dist[aaa][bbb]+tt[x][aaa]+tt[y][bbb];
				}
			}
		}
		cout<<w[x]+w[y]+minn<<endl;
	}
	return 0;
}


