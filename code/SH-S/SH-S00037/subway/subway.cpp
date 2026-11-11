#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n,d,q,w[500005],k,tx,ans;
struct sta{
	int a;
	ll t;
}v[505][100005];
struct staa{
	int a;
	int va;
	ll t;
};
struct st{
	int va,cd;
};
vector<st> av[500005];
int c,ax,x,y;
ll bfs(int ix){
	queue<staa> q;
	ll ab=0;
	while(!q.empty()) q.pop();
	ll txx=10000000000000;
	int vxx;
	for(int i=0;i<av[ix].size();i++){
		int vx=av[ix][i].va,cdx=av[ix][i].cd;
		if(txx>v[vx][cdx].t){
			vxx=vx;
			txx=v[vx][cdx].t;
		}
	}
	q.push({ix,vxx,txx});
	while(!q.empty()){
		staa qx=q.front();
		q.pop();
	}
	return 19;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%lld",&k);
		int cnt=0;
		for(int j=1;j<=k;++j){
			scanf("%d%lld",&ax,&tx);
			v[i][++cnt].a=ax;
			v[i][cnt].t=tx;
			av[ax].push_back({i,cnt});
		}
	}
	for(int i=1;i<=q;++i){
		scanf("%d%d",&x,&y);
		ans=w[x]+w[y];
		ans+=bfs(x);
		printf("%lld\n",ans);
	}
	return 0;
}

