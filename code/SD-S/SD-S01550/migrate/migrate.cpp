#include <bits/stdc++.h>
#define int long long
//#define MOD (1000000007)
//#define eps (1e-6)
#define debug cout<<"debug"<<endl;
#define endl '\n'
using namespace std;
const int MAXN=5010+10;
const int INF=0x7f7f7f7f7f7f7f7fll;
int c,t,n,d,ans;
int x[MAXN],dis[MAXN],in[MAXN];
vector<int> g[MAXN],G[MAXN];
bool mark[MAXN];
queue<int> q;
void dfs(int x){
	mark[x]=true;
	for(int i=0;i<G[x].size();++i) if(!mark[G[x][i]]) dfs(G[x][i]);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
			g[i].clear();
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;++i){
			int r=i+1,l=i-1;
			while(l>=1&&x[i]-x[l]<=d){
				g[i].emplace_back(l);
				--l;
			}
			while(r<=n&&x[r]-x[i]<=d){
				g[i].emplace_back(r);
				++r;
			}
		}
		ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) dis[j]=INF,mark[j]=false,G[j].clear(),in[j]=0;
			q.emplace(i);
			dis[i]=0;
			mark[i]=false;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int j=0;j<g[i].size();++j){
					int v=g[i][j];
					if(dis[v]!=INF){
						if(dis[v]==dis[u]+1){
							G[u].emplace_back(v);
							++in[v];
						}
					}
					else{
						G[u].emplace_back(v);
						++in[v];
						dis[v]=dis[u]+1;
						q.emplace(v); 
					}
				}
			}
			for(int j=1;j<=n;++j){
				if(in[j]>1&&!mark[j]){
					dfs(j);
				}
			}
			for(int j=1;j<=n;++j) if(mark[j]) ++ans;
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
/*
uid:511811
得得得得
50min
我去，美国的NASA这么厉害，居然把我给探测出来了
（火星人叫声）
 我去，你的数数这么厉害，居然把双径岛对给探测出来了
 128min
 脑子要烧糊了 
*/

