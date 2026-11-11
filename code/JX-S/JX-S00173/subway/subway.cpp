#include<bits/stdc++.h>
using namespace std;
int const maxn=500600;
int c,n,m,d,q,a[1005],k[1005],w[maxn],t[1005],dis[maxn],cnt,x,y,vis[maxn];
int inf=0x3f3f3f3f;
void init(){
	for(int i=1;i<=cnt;i++){
		dis[i]=inf;		
		vis[i]=0;
	}	
}
struct node{
	int u,v,w;
}g[500900];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			cnt++;
			g[cnt].u=a[j];
			g[cnt].v=m+i;
			g[cnt].w=t[j];
			cnt++;
			g[cnt].u=m+i;
			g[cnt].v=a[j];
			g[cnt].w=t[j];
		}
	}	
	for(int i=1;i<=cnt;i++){
		if(g[i].w==0)
		g[i].w=inf;
	}			
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		init();
		dis[x]=0;
		for(int i=1;i<n+m;i++){
			for(int j=1;j<=cnt;j++){
				if(dis[g[j].u]+g[j].w<dis[g[j].v]){
					dis[g[j].v]=dis[g[j].u]+g[j].w;
				}	
			}
		}
		cout<<dis[y]+w[y]+w[x]<<endl;	
	}
	return 0;
}	
