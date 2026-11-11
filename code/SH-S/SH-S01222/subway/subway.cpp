#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int MAXN=5e5+510;
const int BIG=1e15;
int c,n,m,d,q,g,y,t,u,v,ans,sum;
int vl[MAXN],sw[MAXN][MAXN],tg[MAXN];
void dfs(int uu,int vv){
	if(sw[uu][vv]!=0){ans=min(ans,sum+sw[uu][vv]);}
	else{
		for(int i=1;i<=m+n;i++){
			if(tg[i]==0&&sw[uu][i]!=0){
				sum+=sw[uu][i];
				tg[uu]=1;
				dfs(i,vv);
				tg[uu]=0;
				sum-=sw[uu][i];
			}
		}
	}
}
signed main(){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>vl[i];
	}
	for(int i=0;i<n;i++){
		cin>>g;
		while(g--){
			cin>>y>>t; 
			sw[m+i+1][y]=t;
			sw[y][m+i+1]=t;
		}
	}
	while(q--){
		cin>>u>>v;
		ans=BIG;
		sum=0;
		dfs(u,v);
		cout<<ans+vl[u]+vl[v]<<endl;
	}
	return 0;
}
