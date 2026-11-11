#include<bits/stdc++.h>
using namespace std;
//bool MS;
const int N=505;
const int M=5e5+5;
typedef long long ll;
const ll Inf=0x3f3f3f3f3f3f3f3f;
int n,m,d,q,w[M];
struct line{
	int k;
	vector<int>a;
	vector<int>t;
}l[N];
namespace subtask1{
	ll dis[N*3][N*3];bitset<N*3> vis;
	vector<pair<int,ll> >g[N*3];
	inline void dijkstra(int s){
		priority_queue<pair<ll,int> >q;
		for(int i=1;i<=n+m;++i)dis[s][i]=Inf,vis[i]=false;
		dis[s][s]=0;q.push({0,s});
		while(!q.empty()){
			int x=q.top().second;q.pop();
			if(vis[x])continue;
			vis[x]=true;
			for(vector<pair<int,ll> >::iterator it=g[x].begin();it!=g[x].end();++it){
				if(!vis[it->first]&&dis[s][x]+it->second<dis[s][it->first]){
					dis[s][it->first]=dis[s][x]+it->second;
					q.push({-dis[s][it->first],it->first});
				}
			}
		}
//		for(int i=1;i<=n+m;++i)cout<<s<<' '<<i<<' '<<dis[s][i]<<'\n';
		return;
	}
	void solve(){
		for(int i=1;i<=n;++i){
			for(int j=0;j<l[i].k;++j){
//				cout<<n+l[i].a[j]<<' '<<i<<' '<<l[i].t[j]<<'\n';
				g[n+l[i].a[j]].emplace_back(i,l[i].t[j]);
				g[i].emplace_back(n+l[i].a[j],l[i].t[j]);
			}
		}
		for(int x=1;x<=m;++x)dijkstra(x+n);
		for(int i=1,x,y;i<=q;++i){
			cin>>x>>y;
			cout<<w[x]+w[y]+dis[x+n][y+n]<<'\n';
		}
		return;
	}
}
//bool MT;
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>l[i].k;
		for(int j=1,a,t;j<=l[i].k;++j){
			cin>>a>>t;
			l[i].a.emplace_back(a);
			l[i].t.emplace_back(t);
		}
	}
	if(m<=1000)return void(subtask1::solve());
//	for(int i=1,x,y;i<=q;++i)cin>>x>>y; 
	subtask1::solve();
	// 44pts
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	int cl=clock();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int _=1,c;cin>>c;
	while(_--)solve();
//	cerr<<fixed<<setprecision(2)<<1.0*(clock()-cl)/CLOCKS_PER_SEC<<"s\n";
//	cerr<<1.0*(&MT-&MS)/1024.0/1024.0<<"MB\n";
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2  7 4  6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
//freopen("subway.in","r",stdin);
华风夏韵，洛水天依！
暂时只会暴力44pts 
*/
