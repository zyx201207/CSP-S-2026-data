#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define lINF 0x3f3f3f3f3f3f3f3f
//第二版 
using namespace std;
void read(ll &x){
	ll f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while (s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	x*=f;
}
const ll N=5e5+505;
ll c,n,m,d,q;
ll dis[505][505];//路线间距 
ll w[N],sta[N][25],l[N][25];//进站时长，连接的线路和时间
void work(){
	for (int i=1;i<=n;i++){
		for (int k=1;k<=n;k++){
			for (int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	memset(dis,0x3f,sizeof(dis));
	for (ll i=1;i<=m;i++) read(w[i]);
	for (ll i=1;i<=n;i++){
		ll k;
		read(k);
		for (ll j=1;j<=k;j++){
			ll x,y;
			read(x);read(y);
			ll t=++sta[x][0];
			sta[x][t]=i;
			l[x][t]=y;
		}

	}
	for (ll i=1;i<=m;i++){
		for (ll j=1;j<=sta[i][0];j++){
			for (ll k=1;k<=sta[k][0];k++){
				int u=sta[i][j],v=sta[i][k];
				dis[u][v]=dis[v][u]=min(dis[u][v],l[i][j]+l[i][k]);
			}
		}
	}
	for (int i=1;i<=n;i++) dis[i][i]=0;
	work(); 
	for (ll i=1;i<=q;i++){
		ll x,y;
		read(x);read(y);
		ll ans=lINF;
		for (ll a=1;a<=sta[x][0];a++){
			for (ll b=1;b<=sta[y][0];b++){
				ans=min(l[x][a]+l[y][b]+dis[sta[x][a]][sta[y][b]],ans);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}

