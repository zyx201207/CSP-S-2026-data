#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
struct node{
	int xl,zt,t;
};
int c,n,m,d,q,k;
vector<node> G[501][N];
int F[501][N];
int djstl(int sx,int sz,int ex,int ez){
	int ans=1e9;
	for(int i=1;i<=n;i++){
		if(F[i][sz]&&F[i][ez]) ans=min(ans,F[i][sz]+F[i][ez]);
	}
	return F[sx][sz]+F[ex][ez]+ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",F[0][i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		int b,d;
		scanf("%d%d",&b,&d);
		F[i][b]=d;
		for(int j=0;j<k;j++){
			int e,f;
			scanf("%d%d",&e,&f);
			F[i][e]=f;
			G[b][d].push_back({e,f,0});
			G[e][f].push_back({b,d,0});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(!F[j][i]) continue;
			for(int k=1;k<=n;k++){
				if(!F[k][i]||j==k) continue;
				G[j][i].push_back({k,i,F[j][i]+F[k][i]});
				G[k][i].push_back({j,i,F[j][i]+F[k][i]});
			}
		}
	}
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u==v) printf("%d\n",0);
		else printf("%d\n",djstl(0,u,0,v));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
