#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,d,m,q,w[500009],k,dis[509][509];
vector<pair<int,int> >g[509];
vector<pair<int,int> >rfr[500009];
inline int read(void){
	int f=0;
	while(true){
		char c=getchar();
		if(c==' '||c=='\n') break;
		f*=10,f+=c-'0';
	}return f;
}int floyd_try(int a,int b){
	if(a==LONG_LONG_MAX||b==LONG_LONG_MAX) return LONG_LONG_MAX;
	else return a+b;
}void floyd(void){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(pair<int,int>j:g[i]){
			int _i,_j;
			if(i>j.first) _i=j.first,_j=i;
			else _i=i,_j=j.first;
			dis[_i][_j]=min(dis[_i][_j],j.second);
		}
	}for(int l=1;l<=n;l++) for(int r=l+1;r<=n;r++) for(int k=l;k<=r;k++) dis[l][r]=min(dis[l][r],floyd_try(dis[l][k],dis[k][r]));
	return;
}signed main(void){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		int a,t;
		for(int j=1;j<=k;j++){
			a=read(),t=read();
			rfr[a].push_back(make_pair(i,t));
		}
	}for(int i=1;i<=m;i++){
		if(rfr[i].size()==0) continue;
		for(int j=0;j<rfr[i].size();j++) for(int l=j+1;l<rfr[i].size();l++){
			g[rfr[i][j].first].push_back(make_pair(rfr[i][l].first,rfr[i][j].second+rfr[i][l].second));
			g[rfr[i][l].first].push_back(make_pair(rfr[i][j].first,rfr[i][j].second+rfr[i][l].second));
		}
	}floyd();
	while(q--){
		int x,y,ans=LONG_LONG_MAX;
		scanf("%lld%lld",&x,&y);
		for(pair<int,int>i:rfr[x]) for(pair<int,int>j:rfr[y]){
			int u=min(i.first,j.first),v=max(i.first,j.first);
			ans=min(ans,dis[u][v]+i.second+j.second+w[x]+w[y]);
		}printf("%lld\n",ans);
	}return 0;
} // I love little lovely miyachn, OvO
