#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[1005];
vector< pair<int,int> > vr[505];
vector< pair<int,int> > vt[1005];
long long dist[1005][1005];
void dfs(int u,int fa,int far) {
	for(int i=0; i<vt[u].size(); i++) {
		if(vt[u][i].first==far) continue;
		int idr=vt[u][i].first;
		for(int j=0; j<vr[idr].size(); j++) {
			if(vr[idr][j].first==fa||vr[idr][j].first==u) continue;
			int idt=vr[idr][j].first;
			if(dist[u][idt]!=2e15&&dist[u][idt]<=vr[idr][j].second+vt[u][i].second) continue;
			dist[u][idt]=vr[idr][j].second+vt[u][i].second;
			dist[idt][u]=dist[u][idt];
			dfs(idt,u,idr);
		}
	}
}
void dfstrt(int ansu,int u,int fa,int far) {
	for(int i=0; i<vt[u].size(); i++) {
		if(vt[u][i].first==far) continue;
		int idr=vt[u][i].first;
		for(int j=0; j<vr[idr].size(); j++) {
			if(vr[idr][j].first==fa||vr[idr][j].first==u) continue;
			int idt=vr[idr][j].first;
			if(dist[ansu][idt]!=2e15&&u!=ansu) {
				continue;
			}
			dist[ansu][idt]=min(dist[ansu][idt],dist[ansu][u]+dist[u][idt]);
			dist[ansu][idt]=min(dist[idt][ansu],dist[ansu][idt]);
			dist[idt][ansu]=min(dist[idt][ansu],dist[ansu][idt]);
			dfstrt(ansu,idt,u,idr);
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
		for(int j=1; j<=m; j++) {
			dist[i][j]=2e15;
			dist[i][i]=0;
		}
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		while(k--) {
			int a,b;
			cin>>a>>b;
			pair<int,int> pte;
			pair<int,int> ptw;
			pte.first=a;
			pte.second=b;
			ptw.first=i;
			ptw.second=b;
			vr[i].push_back(pte);
			vt[a].push_back(ptw);
		}
	}
	for(int i=1;i<=m;i++){
		dfs(i,0,0);
		dfstrt(i,i,0,0);
	}
	for(int i=1; i<=q; i++) {
		int u,v;
		cin>>u>>v;
		if(dist[u][v]>=2e15) dfstrt(u,u,0,0);
		cout<<dist[u][v]+w[u]+w[v];
		cout<<'\n';
	}
	return 0;
}
