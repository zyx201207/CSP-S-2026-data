#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lf double
#define vc vector
#define pb push_back
const ll N=5e5+5e2+5;
ll c,m,n,d,q;
ll w[N];
struct node{
	ll to,dis;
	friend bool operator<(node x,node y){
		return x.dis>y.dis;
	}
};
vc<node>g[N];
ll dis[2005][2005];
bool vis[2005][2005];
void solve1(){//1-11
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			g[m+i].pb({a,t});
			g[a].pb({m+i,t});
		}
	}
	for(int i=1;i<=m+n;i++)for(int j=1;j<=m+n;j++)dis[i][j]=1e18+5;
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
		priority_queue<node>q;
		q.push({i,0});
		while(q.size()){
			node t=q.top();
			q.pop();
			if(vis[i][t.to])continue;
			vis[i][t.to]=1;
			for(node v:g[t.to]){
				if(dis[i][v.to]>dis[i][t.to]+v.dis){
					dis[i][v.to]=dis[i][t.to]+v.dis;
//					cout<<v.to<<' '<<dis[i][v.to]<<'\n';
					q.push({v.to,dis[i][v.to]});
				}
			}
		}
//		for(int j=1;j<=m;j++)cout<<dis[i][j]<<' ';
//		cout<<'\n';
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
}
ll t,dl[505][505];
vc<ll>pt[N];
void solve2(){//12-19
	memset(dl,0x3f,sizeof dl);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		dl[i][i]=0;
		for(int j=1;j<=k;j++){
			ll a;
			cin>>a>>t;
			pt[a].pb(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(pt[i].size()<2)continue;
		for(int j=0;j<pt[i].size();j++){
			for(int jt=j+1;jt<pt[i].size();jt++){
//				cout<<pt[i][j]<<' '<<pt[i][jt]<<'\n';
				dl[pt[i][j]][pt[i][jt]]=dl[pt[i][jt]][pt[i][j]]=t*2;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dl[i][j]=min(dl[i][j],dl[i][k]+dl[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y,ans=1e18+5;
		cin>>x>>y;
//		cout<<x<<' '<<y<<' '<<w[x]<<' '<<w[y]<<'\n';
		for(ll u:pt[x]){
			for(ll v:pt[y]){
				ans=min(dl[u][v],ans);
			}
		}
		cout<<ans+t*2+w[x]+w[y]<<'\n';
	}
}
vc<ll>po[55];
ll tij[N][55];
bool yes[N][55];
void solve3(){//20-21
	ll chv=1e18+5;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
//		cout<<k<<'\n';
		for(int j=1;j<=k;j++){
			ll a;
			cin>>a;cin>>tij[a][i];
			po[i].pb(a);
			yes[a][i]=1;
//			cout<<a<<' '<<tij[a][i]<<'\n';
		}
	}
	for(int i=1;i<=m;i++)if(yes[i][1]&&yes[i][2])chv=min(chv,tij[i][1]+tij[i][2]);
	for(int i=1;i<=q;i++){
		ll x,y,ans=1e9;//ans=min(tij[x][1]+tij[y][1],min(tij[x][2]+tij[y][2],chv+min(tij[x][1]+tij[y][2],tij[x][2]+tij[y][1])));
		cin>>x>>y;
		if(yes[x][1]&&yes[y][1]){
			ans=min(tij[x][1]+tij[y][1],ans);
		}
		if(yes[x][1]&&yes[y][2]){
			if(ans>tij[x][1]+tij[y][2]+chv)ans=tij[x][1]+tij[y][2]+chv;
//			ans=min(tij[x][1]+tij[y][2]+chv,ans);
		}
		if(yes[x][2]&&yes[y][2]){
			if(ans>tij[x][2]+tij[y][2])ans=tij[x][2]+tij[y][2];
//			ans=min(tij[x][2]+tij[y][2],ans);
		}
		if(yes[x][2]&&yes[y][1]){
			if(ans>tij[x][2]+tij[y][1]+chv)ans=tij[x][2]+tij[y][1]+chv;
//			ans=min(tij[x][2]+tij[y][1]+chv,ans);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
void solve(){//22-25
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(1<=c&&c<=11)solve1();
	if(12<=c&&c<=19)solve2();
	if(20<=c&&c<=21)solve3();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
