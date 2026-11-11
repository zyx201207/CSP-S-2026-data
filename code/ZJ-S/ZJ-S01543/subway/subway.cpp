#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,D,q,w[500050],k,a,T,x,y,d[550][550],an;
vector<int> v[500050],t[500050];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) d[i][j]=1e18;
		d[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		while(k--){
			scanf("%lld%lld",&a,&T);
			v[a].push_back(i);
			t[a].push_back(T);
		}
	}
	for(int i=1;i<=m;i++){
		for(x=0;x<v[i].size();x++){
			for(y=0;y<v[i].size();y++) d[v[i][x]][v[i][y]]=min(d[v[i][x]][v[i][y]],t[i][x]+t[i][y]);
		}
	}
	for(k=1;k<=n;k++){
		for(x=1;x<=n;x++){
			for(y=1;y<=n;y++) d[x][y]=min(d[x][y],d[x][k]+d[k][y]);
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		an=1e18;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++) an=min(an,d[v[x][i]][v[y][j]]+t[x][i]+t[y][j]);
		}
		printf("%lld\n",an+w[x]+w[y]);
	}
	return 0;
}