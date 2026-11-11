#include <iostream>
#include <cstdio>
#include <vector>
#define lnl long long
using namespace std;
const lnl INF=2e16;
struct PLP{int to;lnl w;};
int C,n,m,D,Q,mtrsz[505];
lnl WWW[500005],ans,dis[505][505];
vector<PLP> mtr[505];
vector<PLP> zd[500005];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int i,j,k,h,x,y,upsz,qqsz;
	PLP ooo,ppp;
	cin>>C>>n>>m>>D>>Q;
	for(i=1;i<=m;i++){
		cin>>WWW[i];
	}
	
	for(i=1;i<=n;i++){
		cin>>mtrsz[i];
		for(j=1;j<=mtrsz[i];j++){
			cin>>ooo.to>>ooo.w;
			mtr[i].push_back(ooo);
			ppp.w=ooo.w;ppp.to=i;
			zd[ooo.to].push_back(ppp);
		}
		
		dis[i][i]=0ll;
		for(j=i+1;j<=n;j++){
			dis[i][j]=INF;
			dis[j][i]=INF;
		}
	}
	
	for(i=1;i<=m;i++){
		upsz=zd[i].size();
		for(j=0;j<upsz;j++){
			x=zd[i][j].to;
			for(k=j+1;k<upsz;k++){
				y=zd[i][k].to;
				dis[x][y]=min(dis[x][y],zd[i][j].w+zd[i][k].w);
			}
		}
	}
	/*for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(dis[i][j]!=INF)
			cout<<"["<<i<<","<<j<<"]"<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			dis[i][j]=min(dis[i][j],dis[j][i]);
			dis[j][i]=dis[i][j];
		}
	}
	while(Q--){
		cin>>x>>y;
		ans=INF;
		upsz=zd[x].size();
		qqsz=zd[y].size();
		for(i=0;i<upsz;i++){
			k=zd[x][i].to;
			for(j=0;j<qqsz;j++){
				h=zd[y][j].to;
				ans=min(ans,zd[x][i].w+zd[y][j].w+dis[k][h]);
			}
		}
		ans+=WWW[x]+WWW[y];
		cout<<ans<<'\n';
	}
	return 0;
}
