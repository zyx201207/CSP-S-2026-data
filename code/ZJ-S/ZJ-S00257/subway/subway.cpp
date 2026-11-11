#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
const ll inf=1e17+7;
const int N=505;
const int M=5e5+5;
const int mod=998244353;
int tid,n,m,d,q,a[M];
vector<pii> g[M];
ll f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&tid,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	int x,y;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			for(pii it:g[x]){
				int v=it.fi;
				f[i][v]=min(f[i][v],0ll+it.se+y);
				f[v][i]=f[i][v];
			}
			g[x].pb({i,y});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		ll ans=inf;
		for(pii lt:g[x]) for(pii rt:g[y]){
			int u=lt.fi,v=rt.fi;
			//printf("uv:%d %d %lld\n",u,v,f[u][v]);
			ans=min(ans,f[u][v]+lt.se+rt.se);
		}
		ans+=a[x]+a[y];
		printf("%lld\n",ans);
	}
	return 0;
}