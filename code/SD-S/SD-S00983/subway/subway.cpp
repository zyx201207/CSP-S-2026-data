#include<bits/stdc++.h>

using namespace std;

#define ll long long

inline ll Rd(){
	ll x=0,f=1; int c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar(); 
	}
	while (c>='0'&&c<='9'){
		x=x*10+(c^'0');
		c=getchar();
	}
	return x*f;
}


ll testnum,n,m,d,Q;
ll aw[500005];

ll f[510][510];
struct edge{
	ll v,w;
};
vector<edge> e[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	testnum=Rd();
	n=Rd();m=Rd();d=Rd();Q=Rd();
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			f[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for (int i=1;i<=n;i++) f[i][i]=0;
	
	for (int i=1;i<=m;i++){
		aw[i]=Rd();
	}
	for (int i=1;i<=n;i++){
		ll k=Rd();
		for (int j=1;j<=k;j++){
			ll x=Rd(),w=Rd();
			e[x].push_back((edge){i,w});
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=0;j<e[i].size();j++){
			for (int k=0;k<e[i].size();k++){
				f[e[i][j].v][e[i][k].v]=f[e[i][k].v][e[i][j].v]=min(f[e[i][j].v][e[i][k].v], e[i][j].w+e[i][k].w);
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
			}
		}
	}
	
	for (int k=1;k<=Q;k++){
		ll x=Rd(),y=Rd();
		ll ans=0x3f3f3f3f3f3f3f3f;
		for (int i=0;i<e[x].size();i++){
			for (int j=0;j<e[y].size();j++){
				ans=min(ans, e[x][i].w + e[y][j].w + f[e[x][i].v][e[y][j].v]);
			}
		}
		ans=ans+aw[x]+aw[y];
		printf("%lld\n",ans);
	}
	return 0;
}
