#include<bits/stdc++.h>
using namespace std;
struct edge{
	int v,w;
};
int c,n,m,d,q;
int w[500005];
vector<edge> e[500005];
int dj[500005],vis[500005];
int djs(int x,int y){
	for(int i=1;i<=m;i++){
		dj[i]=INT_MAX;
		vis[i]=0;
	}
	dj[x]=0;
	for(int s=1;s<m;s++){
		int mi=INT_MAX;
		int mj=0;
		for(int i=1;i<=m;i++){
			if(mi>dj[i]&&vis[i]==0){
				mi=dj[i];
				mj=i;
			}
		}
		vis[mj]=1;
		for(int i=0;i<int(e[mj].size());i++){
			if(vis[e[mj][i].v]==0){
				dj[e[mj][i].v]=min(dj[e[mj][i].v],dj[mj]+e[mj][i].w);
			}
		}
	}
	return dj[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		int a[k+5],t[k+5];
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
			for(int l=1;l<j;l++){
				edge s;
				s.v=a[l];
				s.w=t[l]+t[j];
				e[a[j]].push_back(s);
				s.v=a[j];
				e[a[l]].push_back(s);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		cout<<djs(x,y)+w[x]+w[y]<<'\n';
	}
    return 0;
}