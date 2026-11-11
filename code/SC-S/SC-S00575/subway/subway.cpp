#include<bits/stdc++.h>
using namespace std;
const int N=5e2+9,M=5e5+9;
const long long MAXN=1e18+9;
#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
int c,n,m,d,q;
LL a[M],sval,sid;
vector< pair<int,LL> > pos[M];
LL dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for(int i=1,kk;i<=n;i++){
		scanf("%d",&kk);
		for(int j=1;j<=kk;j++){
			scanf("%lld%lld",&sid,&sval);
			pos[sid].push_back({i,sval});
		}
	}
	FOR(i,1,n) FOR(j,1,n) dis[i][j]=MAXN;
	FOR(i,1,n) dis[i][i]=0;
	for(int i=1;i<=m;i++) if(pos[i].size()>1){
		int o=pos[i].size();
		for(int j=0;j<o;j++) for(int k=j+1;k<o;k++){
			int id1=pos[i][j].first,id2=pos[i][k].first;
			dis[id1][id2]=min(dis[id1][id2],pos[i][j].second+pos[i][k].second);
			dis[id2][id1]=dis[id1][id2];
		}
	}
	FOR(k,1,n) FOR(i,1,n) FOR(j,1,n){
		if(i==j||i==k||j==k) continue;
		if(dis[i][k]==MAXN||dis[k][j]==MAXN) continue;
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	for(int i=1,sx,sy;i<=q;i++){
		scanf("%d%d",&sx,&sy);
		LL ans=MAXN;
		for(auto l:pos[sx]) for(auto r:pos[sy]){
			int ll=l.first,rr=r.first;
			ans=min(ans,l.second+r.second+dis[ll][rr]);
		}
		ans+=a[sx]+a[sy]; 
		printf("%lld\n",ans);
	} 
	return 0;
}