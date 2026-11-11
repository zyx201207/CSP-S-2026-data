#include<bits/stdc++.h>
#define ll long long
#define maxn 505
#define maxm 500005
#define maxq 100005
#define maxd 22
using namespace std;
int sta[maxm][maxd];
int tim[maxm][maxd];
int siz[maxm];
ll dis[maxn][maxn];
ll c,n,m,d,q;
ll w[maxm];
void input(){
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			siz[a]++;
			sta[a][siz[a]]=i;
			tim[a][siz[a]]=t;
		}
	}
}
void init(){
	for(ll i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=siz[i];j++){
			for(ll k=j+1;k<=siz[i];k++){
				dis[sta[i][j]][sta[i][k]]=min(dis[sta[i][j]][sta[i][k]],(ll)(tim[i][j]+tim[i][k]));
			}
		}
	}
}
void sp(){
	for(ll i=1;i<=n;i++){
		for(ll k=1;k<=n;k++){
			for(ll j=1;j<=n;j++){
				dis[k][j]=min(dis[k][j],dis[i][j]+dis[i][k]);
				dis[j][k]=dis[k][j];
			}
		}
	}
}
void answer(){
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		ll minans=1000000000000000000;
		for(ll j=1;j<=siz[x];j++){
			for(ll k=1;k<=siz[y];k++){
				minans=min(minans,tim[x][j]+tim[y][k]+dis[sta[x][j]][sta[y][k]]);
			}
		}
		cout<<minans+w[x]+w[y]<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	init();
	sp();
	answer();
}