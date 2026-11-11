#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int w[20010],g[20010][20010],dist[20010],a[20010],t[20010];
bool st[200010];
int n,m;
int dijkstra(int x,int y){
	memset(st,0,sizeof st);
	memset(dist,0x3f,sizeof dist);
	dist[x]=0;
	for(int i=1;i<m;i++){
		int t=-1;
		for(int j=1;j<=m;j++){
			if(t==-1||(!st[j]&&dist[j]<dist[t])){
				t=j;
			}
		}st[t]=1;
		for(int j=1;j<=m;j++){
			dist[j]=min(dist[j],dist[t]+g[t][j]);
		}
	}return dist[y];
}signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int kk=1;kk<j;kk++){
				g[a[j]][a[kk]]=min(g[a[j]][a[kk]],t[j]+t[kk]);
				g[a[kk]][a[j]]=min(g[a[kk]][a[j]],t[j]+t[kk]);
			}
		}
	}for(int i=1;i<=q;i++){
		int xx,yy;
		cin>>xx>>yy;
		cout<<w[xx]+w[yy]+dijkstra(xx,yy)<<'\n';
	}return 0;
}
