#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<pair<int,int> , vector<pair<int,int> > ,greater<pair<int,int> > >q;
const int N=5e5+5;
int c,n,m,d,Q;
int v[N];
vector<pair<int,int> > a[505];
vector<pair<int,int> > f[N];
int dis[505][505];
bool usd[505];
inline void read(int &x){
	x=0;
	bool nag=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') nag=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	if(nag) x=-x;
}
inline void dij(int x){
	memset(usd,0,sizeof(usd));
	for(int i=1;i<=n;++i){
		dis[x][i]=1e18;
	}
	dis[x][x]=0;
	q.push({0,x});
	while(!q.empty()){
		int nx=q.top().second;
		q.pop();
		if(usd[nx]) continue;
		usd[nx]=1;
		for(auto it:a[nx]){
			int y=it.second;
			for(auto to:f[y]){
				int now=to.second;
				if(dis[x][nx]+it.first+to.first<dis[x][now]){
					dis[x][now]=dis[x][nx]+it.first+to.first;
					q.push({dis[x][now],now});
				}
			}
		}
	}
}
inline void solve(){
	read(c),read(n),read(m),read(d),read(Q);
	int x,t;
	for(int i=1;i<=m;++i){
		read(v[i]);
	}
	int k;
	int sum=0;
	for(int i=1;i<=n;++i){
		read(k);
		sum+=k;
		for(int j=1;j<=k;++j){
			read(x),read(t);
			a[i].push_back({t,x});
			f[x].push_back({t,i});
		}
	}
	for(int i=1;i<=n;++i){
		dij(i);
	}
	int y;
	for(int i=1;i<=Q;++i){
		read(x),read(y);
		int minn=1e18;
		for(auto now:f[x]){
			for(auto to:f[y]){
				minn=min(minn,now.first+to.first+dis[now.second][to.second]);
			}
		}
		cout<<minn+v[x]+v[y]<<'\n';
	}
}     

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
