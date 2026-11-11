#include<bits/stdc++.h>
using namespace std;
#define gc getchar
typedef long long ll;
typedef pair<int,ll> P;
const ll inf = 1e18;
#define N 500005
#define M 505
int _,n,m,d,q,w[N];//n:station m:line
ll dis[M][M];
vector<P>g[N];
inline int read(){
	int k=0,f=1,c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())k=k*10+(c^48);
	return k*f;
}
inline void write(ll x){
//	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);putchar('0'+x%10);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	_=read();m=read();n=read();d=read();q=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=m;i++){
		int cnt=read();
		while(cnt--){
			int x,t;x=read();t=read();
			g[x].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)dis[i][j]=inf;
	for(int i=1;i<=m;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(P X:g[i]){
			for(P Y:g[i]){
				ll w1=X.second,w2=Y.second;int x=X.first,y=Y.first;
				if(x==y)continue;
				dis[x][y]=min(dis[x][y],w1+w2);
				dis[y][x]=min(dis[y][x],w1+w2);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int l,r;l=read();r=read();
		ll ans=inf;
		for(P X:g[l]){
			for(P Y:g[r]){
				ll w1=X.second,w2=Y.second;int x=X.first,y=Y.first;
				if(ans>w1+w2+dis[x][y])ans=w1+w2+dis[x][y];
			}
		}
		write(ans+w[l]+w[r]);putchar('\n');
//		printf("%lld\n",ans+w[l]+w[r]);
	}
	return 0;
}