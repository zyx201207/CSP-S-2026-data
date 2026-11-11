#include <bits/stdc++.h>
using namespace std;
long long GM,n,i,j,xx,m,D,T,x,y,w[500010],dis[500010],t[510][1010];
long long hc[500010];
vector<long long>f[500010],g[500010];
queue<long long>q;
void bfs(long long x){
	long long i,j;
	for(j=1;j<=m;j++) dis[j]=1e18;
	dis[x]=0;q.push(x);
	while(!q.empty()){
		long long fx=q.front();q.pop();
		for(i=0;i<f[fx].size();i++){
			long long sx=f[fx][i];
			long long metro=g[fx][i];
			if(dis[fx]+t[metro][fx]+t[metro][sx]<dis[sx]){
				dis[sx]=dis[fx]+t[metro][fx]+t[metro][sx];
				q.push(sx);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>GM>>n>>m>>D>>T;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>xx;
		long long jc=-1;
		for(j=1;j<=xx;j++)cin>>hc[j],cin>>t[i][hc[j]];
		for(j=1;j<xx;j++)
			for(long long k=j+1;k<=xx;k++)
				f[hc[j]].push_back(hc[k]),g[hc[j]].push_back(i),
				f[hc[k]].push_back(hc[j]),g[hc[k]].push_back(i);
	}
	while(T--){
		cin>>x>>y;
		bfs(x);
		long long mi=1e18;
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
pts=32
ÆÀ²â»ú±£ÓÓÎÒ 
*/
