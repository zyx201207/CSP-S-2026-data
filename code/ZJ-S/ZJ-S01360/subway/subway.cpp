#include<bits/stdc++.h>
#define fst first
#define sec second
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL;
typedef pair<int,LL> pii;
const int maxn=505;
const int maxm=5e5+5;
const LL inf=1e18+1;
void read(LL& x){
	char c; bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=(x<<3)+(x<<1)+c-48;
	x=(f ? -x : x);
}
void read(int& x){
	char c; bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=(x<<3)+(x<<1)+c-48;
	x=(f ? -x : x);
}
int c,n,m,d,q;
LL dis[maxn][maxn],wk[maxm];
vector<pii> mp[maxm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) read(wk[i]);
	for(int i=1;i<=n;i++){
		int k; read(k);
		for(int j=1;j<=k;j++){
			int u; LL w; read(u),read(w);
			mp[u].push_back(mkp(i,w));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)mp[i].size();j++){
			for(int k=0;k<(int)mp[i].size();k++){
				if(j==k) continue;
				int u=mp[i][j].fst,v=mp[i][k].fst;
				LL w=mp[i][j].sec+mp[i][k].sec;
				dis[u][v]=dis[v][u]=min(dis[u][v],w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		int u,v; read(u),read(v);
		LL ans=inf;
		for(int j=0;j<(int)mp[u].size();j++){
			for(int k=0;k<(int)mp[v].size();k++){
				ans=min(ans,dis[mp[u][j].fst][mp[v][k].fst]+mp[u][j].sec+mp[v][k].sec);
			}
		}
		ans+=wk[u]+wk[v];
		printf("%lld\n",ans);
	}
	return 0;
}