#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
ll f[N][N],w[M];
struct node{
	int v;
	ll t;
};
vector<node>e[M];
void read(int &x){
	x=0;
	int sg=1;
	char now;
	while(true){
		now=getchar();
		if(now=='-')
			sg=-1;
		if(now>='0'&&now<='9')
			break;
	}
	while(now>='0'&&now<='9'){
		x=x*10+(now-'0');
		now=getchar();
	}
	x*=sg;
}
void read(ll &x){
	x=0;
	int sg=1;
	char now;
	while(true){
		now=getchar();
		if(now=='-')
			sg=-1;
		if(now>='0'&&now<='9')
			break;
	}
	while(now>='0'&&now<='9'){
		x=x*10+(now-'0');
		now=getchar();
	}
	x*=sg;
}
signed main(){
	memset(f,0x3f,sizeof(f));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=m;i++)
		read(w[i]);
	for(int i=1;i<=n;i++){
		int k,a;
		ll t;
		read(k);
		while(k--){
			read(a);
			read(t);
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(node &u:e[i])
			for(node &v:e[i])
				f[u.v][v.v]=min(f[u.v][v.v],u.t+v.t);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(node &u:e[x])
			for(node &v:e[y])
				ans=min(ans,f[u.v][v.v]+u.t+v.t);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}