#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PLI pair<ll,int>
using namespace std;
const int M=5e5+5,N=505;
const ll inf=(1LL<<60);
int c,n,m,d,q;
ll ans;
int w0[M];
vector<int> t[N];
vector<int> line[M];
vector<PLI> G[N];
map<int,int> id[N];
void dfs(int u,ll cost,int en){
	if(u==en){
		ans=min(ans,cost);
		return;
	}
	for(auto [w,v]:G[u])dfs(v,cost+w,en);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w0[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		t[i].push_back(k);
		for(int j=1;j<=k;j++){
			int aij,tij;cin>>aij>>tij;
			id[i][aij]=j;
			t[i].push_back(tij);
			line[aij].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(unsigned j=0;j<line[i].size();j++){
			for(unsigned k=j+1;k<line[i].size();k++){
				int u=line[i][j],v=line[i][k];
				G[u].push_back({(ll)(t[u][id[u][i]]+t[v][id[v][i]]),v});
				G[v].push_back({(ll)(t[u][id[u][i]]+t[v][id[v][i]]),u});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		ans=inf;
		for(int s:line[x]){
			for(int e:line[y]){
				//cout<<s<<' '<<e<<endl;
				//cout<<w0[x]+t[s][x]+w0[y]+t[e][y]<<endl;
				dfs(s,w0[x]+t[s][id[s][x]]+w0[y]+t[e][id[e][y]],e);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2 
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
