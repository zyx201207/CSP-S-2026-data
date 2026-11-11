#include<bits/stdc++.h>
#define int long long
using namespace std;
struct sub{int l,f;};
int c,n,m,d,q;
int w[500009],k;
int mi[509][509];
vector<sub> stat[500009];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(register int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(register int i=1;i<=n;i++){
		scanf("%lld",&k);
		while(k--){
			int xx,tt;
			scanf("%lld%lld",&xx,&tt);
			sub y;
			y.l=i,y.f=tt;
			stat[xx].push_back(y);
		}
	}
	for(register int i=1;i<=n;i++){
		for(register int j=i+1;j<=n;j++){
			mi[i][j]=1e18;
			mi[j][i]=1e18;
		}
	}
	for(register int i=1;i<=m;i++){
		for(register int j=0;j<stat[i].size();j++){
			for(register int k=j+1;k<stat[i].size();k++){
				mi[stat[i][j].l][stat[i][k].l]=min(mi[stat[i][j].l][stat[i][k].l],stat[i][j].f+stat[i][k].f);
				mi[stat[i][k].l][stat[i][j].l]=mi[stat[i][j].l][stat[i][k].l];
			}
		}
	}
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=n;j++){
			if(i==j) continue;
			for(register int k=j+1;k<=n;k++){
				if(i==k) continue;
				mi[k][j]=min(mi[k][j],mi[k][i]+mi[j][i]);
				mi[j][k]=mi[k][j];
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=1e18;
		for(register int i=0;i<stat[x].size();i++){
			for(register int j=0;j<stat[y].size();j++){
				ans=min(ans,mi[stat[x][i].l][stat[y][j].l]+stat[x][i].f+stat[y][j].f);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
