#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q,w[M],k,res;
int h[N][N],dis[N][N];
vector<int> g[N];
vector<pii> st[M];
void dfs(int u0,int u){
	for(int v:g[u]){
		if(dis[u0][v]>dis[u0][u]+h[u][v]){
			dis[u0][v]=dis[u0][u]+h[u][v];
			dis[v][u0]=dis[u0][u]+h[u][v];
			dfs(u0,v);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k;
		int ta,tt;
		for(int j=1;j<=k;++j){
			cin>>ta>>tt;
			st[ta].push_back(make_pair(i,tt));
		}
	}
	/*for(int i=1;i<=m;++i){
		for(pii j:st[i]){
			cout<<j.first<<' '<<j.second<<'\n';
		}
	}*/
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			h[i][j]=dis[i][j]=1e18+10;
		}
		h[i][i]=dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(pii u:st[i]){
			for(pii v:st[i]){
				if(u!=v){
					bool flag=true;
					for(int j:g[u.first]){
						if(j==v.first) flag=false;
					}
					if(flag){
						g[u.first].push_back(v.first);
						g[v.first].push_back(u.first);
					}
					h[u.first][v.first]=min(u.second+v.second,h[u.first][v.first]);
					h[v.first][u.first]=min(u.second+v.second,h[v.first][u.first]);
				}
			}
		}
	}
	/*for(int i:g[1]) cout<<i<<' ';
	cout<<'\n';
	for(int i:g[2]) cout<<i<<' ';
	cout<<'\n';
	cout<<h[1][2]<<' '<<h[2][1]<<' '<<h[1][1]<<' '<<h[2][2];*/
	int x,y;
	for(int i=1;i<=n;++i){
		dfs(i,i);
	}
	//cout<<dis[1][1]<<' '<<dis[1][2];
	while(q--){
		cin>>x>>y;
		res=1e18+10;
		for(pii u:st[x]){
			for(pii v:st[y]){
				res=min(dis[u.first][v.first]+u.second+v.second,res);
			}
		}
		res+=w[x]+w[y];
		cout<<res<<'\n';
	}
	return 0;
}
