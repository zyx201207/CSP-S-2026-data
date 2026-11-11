#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500050;
const int INF=0x3f3f3f3f3f3f3f3f;
int rd(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void wrt(int x){
	if(!x)putchar('0');
	if(x<0)putchar('-');
	if(x>9)wrt(x/10);
	putchar(x%10+'0');
}
struct edge{int u,l;};
int c,n,m,d,q;
int dis[520][520],w[N];
vector<edge>g1[520],g2[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++)w[i]=rd();
	for(int i=1;i<=n;i++){
		int k=rd();
		while(k--){
			int u=rd(),l=rd();
			g1[i].push_back({u,l});
			g2[u].push_back({i,l});
		}
	}
	for(int i=0;i<520;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)
		for(auto e:g1[i])
			for(auto j:g2[e.u])dis[i][j.u]=min(dis[i][j.u],e.l+j.l);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u=rd(),v=rd();
		int ans=INF;
		for(auto x:g2[u])for(auto y:g2[v])ans=min(ans,x.l+y.l+dis[x.u][y.u]);
		wrt(ans+w[u]+w[v]);
		putchar('\n');
	}
}
