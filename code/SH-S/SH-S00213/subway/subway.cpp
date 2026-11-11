#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll N=5e5+10,M=505,INF=100000000000000000;
ll c,n,m,d,q,w[N],k[N],dst[M][M];
vector<pii> z[N];
ll read(){
	ll res=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') ch=getchar();
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar((x%10)^48);
}
void build(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dst[i][j]=INF;
	for(int i=1;i<=m;i++){
		int l=z[i].size();
		for(int j=0;j<l;j++)
			for(int k=j+1;k<l;k++){
				dst[z[i][j].fi][z[i][k].fi]=min(dst[z[i][j].fi][z[i][k].fi],z[i][j].se+z[i][k].se);
				dst[z[i][k].fi][z[i][j].fi]=dst[z[i][j].fi][z[i][k].fi];
			}
	}
	for(int i=1;i<=n;i++)
		dst[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dst[j][i]=dst[i][j]=min(dst[i][k]+dst[k][j],dst[i][j]);
}
ll get(ll s,ll e){
	ll res=INF;
	for(int i=0;i<z[s].size();i++){
		for(int j=0;j<z[e].size();j++){
			res=min(res,dst[z[s][i].fi][z[e][j].fi]+z[s][i].se+z[e][j].se);
		}
	}
	return res+w[s]+w[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			ll zh=read(),dis=read();
			z[zh].push_back(mp(i,dis));
		}
	}
	build();
	while(q--){
		ll s=read(),e=read();
		write(get(s,e));
		putchar('\n');
	}
	return 0;
}
