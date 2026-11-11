#include<bits/stdc++.h>
using namespace std;
#define int long long
#define repr(i,a,b) for(int i = a;i <= b;i++)
const int MAXN = 500005;
int w[MAXN],k[MAXN],dis[MAXN];
int a[5005][5005];
int t[5005][5005];
int n;
bool vis[MAXN];
vector<pair<int,int> > e[MAXN];
void dfs(int u,int fa){
	for(auto v:e[u]){
		if(v!=fa) dfs(v,u);
	}
}
void dij(int s){
	fill(dis+1,dis+n+1,0x7fffffff);
	dis[s] = 0;
	priority_queue<int> q;
	while(!q.empty()){
		int u = q.top();
		q.pop();
		if(!vis[u]){
			vis[u] = 1;
			for(auto v:e[u]){
				if(dis[v.first]>dis[u]+v.second){
					dis[v.first] = dis[u]+v.second;
				}
			}
		}
	}
	return dis[n];
}
void dij1(int s){
	fill(dis+1,dis+n+1,0x7fffffff);
	dis[s] = 0;
	priority_queue<int> q;
	while(!q.empty()){
		int u = q.top();
		q.pop();
		if(!vis[u]){
			vis[u] = 1;
			for(auto v:e[u]){
				if(dis[v.first]<dis[u]+v.second){
					dis[v.first] = dis[u]+v.second;
				}
			}
		}
	}
	return dis[n];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	repr(i,1,m){
		cin>>w[i];
	}
	repr(i,1,n){
		cin>>k[i];
		repr(j,1,k[i]){
			cin>>a[i][j]>>t[i][j];
			e[i].push_back{make_pair(a[i][j],t[i][j])};
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dij(r)-dij1(l)<<endl;//min-max
	}
	//duo ce qing kong
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
