#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=510;
const int M=5e5+10;
int c,n,m,d,q;
int w[M];
int k[N];
vector<int> a[N],t[N];
vector<pair<int,int> > p[M];
ll dis[N][N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x),t[i].push_back(y);
			p[x].push_back({i,j});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		if((int)p[i].size()==1) continue;
		else{
			for(auto u:p[i])
				for(auto v:p[i]){
					if(u.first==v.first) continue;
					dis[u.first][v.first]=(ll)t[u.first][u.second-1]+t[v.first][v.second-1];
					dis[v.first][u.first]=(ll)t[u.first][u.second-1]+t[v.first][v.second-1];
				}
		}
	}
	for(int kk=1;kk<=n;++kk)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(auto x:p[u]){
			for(auto y:p[v]){
				ans=min(ans,t[x.first][x.second-1]+t[y.first][y.second-1]+dis[x.first][y.first]+w[u]+w[v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
