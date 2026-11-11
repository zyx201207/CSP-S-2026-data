#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,p;
int w[N],k[505],a[505][N],t[505][N];
long long vis[N],dis[N];
queue<int> q;
long long dij(int x,int z) {
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	while(!q.empty()) q.pop();
	vis[x]=1;
	dis[x]=0;
	q.push(x);
	while(!q.empty()) {
		int s=q.front();
		q.pop();
		for(int i=1; i<=n; i++) {
			bool f=0;
			int id=0;
			for(int j=1; j<=k[i]; j++) {
				if(s==a[i][j]){
					f=1;
					id=j;
				} 
			}
			if(!f) continue;
			for(int j=1; j<=k[i]; j++) {
				if(a[i][j]==id) continue;
				if(dis[a[i][j]]>dis[s]+w[s]+t[i][id]) {
					dis[a[i][j]]=dis[s]+w[s]+t[i][id];
					if(!vis[a[i][j]]){
						vis[a[i][j]]=1;
						q.push(a[i][j]);
					} 
				}
			}
		}
	}
	return dis[z]+w[z];
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) cin>>a[i][j]>>t[i][j];
	}
	while(p--) {
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y);
	}
	return 0;
}
