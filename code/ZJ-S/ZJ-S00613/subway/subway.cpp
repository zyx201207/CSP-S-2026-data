#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn=520,maxm=5e5+10,maxd=25;
const ll inf=1e18;
int c,n,m,d,q,W[maxm];
int B[maxm][maxd],T[maxm][maxd],cnt[maxm];
ll f[maxn][maxn];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>W[i];
	for(int i=1,k; i<=n; i++) {
		cin>>k;
		for(int j=1,a,t; j<=k; j++) {
			cin>>a>>t;
			cnt[a]++;
			B[a][cnt[a]]=i,T[a][cnt[a]]=t;
		}
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) f[i][j]=inf;
	for(int i=1; i<=n; i++) f[i][i]=0ll;
	for(int i=1; i<=m; i++) {
		int len=cnt[i];
		for(int j=1; j<=len; j++) for(int k=j+1; k<=len; k++) {
				int u=B[i][j],v=B[i][k];
				ll w=1ll*T[i][j]+1ll*T[i][k];
				if(f[u][v]<=w) continue;
				f[u][v]=f[v][u]=w;
			}
	}
	for(int k=1; k<=n; k++) for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1,x,y; i<=q; i++) {
		cin>>x>>y;
		int lenx=cnt[x],leny=cnt[y];
		ll ans=1e18;
		for(int X=1; X<=lenx; X++) for(int Y=1; Y<=leny; Y++) {
				int u=B[x][X],v=B[y][Y];
				ll w=1ll*T[x][X]+1ll*T[y][Y];
				ans=min(ans,w+f[u][v]);
			}
		cout<<ans+1ll*W[x]+1ll*W[y]<<"\n";
	}
	return 0;
}
/*
ru guo wo neng qiu chu
di,j
biao shi di i ge zhan ting dao di j ge zhan tai
xun wen shi mei ju zhong zhuan zhan tai
zhe ti jiu ke yi zuo le
*/
