#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,l,x,y,z,s,d,h,o,u,q,t,w;
int a[1010],b[1000100],c[1000100],e[1010][1010],r[10001000],p[1010][1010],v[1010];
vector <int> f[200100],g[200100];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>o>>m>>n>>u>>q;
	memset(p,127,sizeof(p));
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++){
		cin>>x;
		for(j=1;j<=x;j++) cin>>b[j]>>c[j];
		for(j=1;j<=x-1;j++){
			for(k=j+1;k<=x;k++)
				p[b[k]][b[j]]=p[b[j]][b[k]]=min(p[b[j]][b[k]],c[j]+c[k]);
		}
	}
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++){
			if(p[i][j]!=9187201950435737471){
				f[i].push_back(j);
				f[j].push_back(i);
				g[i].push_back(p[i][j]);
				g[j].push_back(p[i][j]);
			}
		}
	memset(e,127,sizeof(e));
	while(q--){
		cin>>x>>y;
		if(e[x][y]!=9187201950435737471){
			cout<<e[x][y]+a[x]+a[y]<<"\n";
			continue;
		}
		t=1;w=1;e[x][x]=0;r[1]=x;
		while(t<=w){
			for(i=0;i<f[r[t]].size();i++){
				if(e[x][f[r[t]][i]]>e[x][r[t]]+g[r[t]][i]){
					e[x][f[r[t]][i]]=e[x][r[t]]+g[r[t]][i];
					if(v[f[r[t]][i]]==0) v[f[r[t]][i]]=1,w++,r[w]=f[r[t]][i];
				}
			}
			t++;v[t]=0;
		}
		cout<<e[x][y]+a[x]+a[y]<<"\n";
	}
	return 0;
}