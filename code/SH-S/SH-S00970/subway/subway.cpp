#include<bits/stdc++.h>
#define int long long
using namespace std;
struct r{
	int t,w;
	bool friend operator <(r a,r b){
		return a.w>b.w;
	}
};
int c,n,m,d,q,w[500010],k,a1,t1,x,y,cnt_t[500010],dis[510][510];
vector<int> t[500010],ve[500010];
vector<pair<int,int>> g[510];
map <int,int> ma[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>a1>>t1;
			t[a1].push_back(t1);
			ma[a1][i]=cnt_t[a1]++;
			ve[a1].push_back(i);
			
		}
	}for (int i=1;i<=m;i++){
		for (int j=0;j<ve[i].size();j++){
			for (int z=j+1;z<ve[i].size();z++){
				g[ve[i][j]].push_back({ve[i][z],t[i][ma[i][ve[i][j]]]+t[i][ma[i][ve[i][z]]]});
				g[ve[i][z]].push_back({ve[i][j],t[i][ma[i][ve[i][j]]]+t[i][ma[i][ve[i][z]]]});
			}
		}
	}for (int i=1;i<=n;i++){
		int vis[510];
		for (int j=1;j<=n;j++){
			vis[j]=0;
			dis[i][j]=1e18;
		}priority_queue<r> qu;
		qu.push({i,0});
		dis[i][i]=0;
		while (!qu.empty()){
			r z=qu.top();
			qu.pop();
			if (vis[z.t]){
				continue;
			}vis[z.t]=1;
			for (int j=0;j<g[z.t].size();j++){
				if (dis[i][z.t]+g[z.t][j].second<dis[i][g[z.t][j].first]){
					dis[i][g[z.t][j].first]=dis[i][z.t]+g[z.t][j].second;
					qu.push({g[z.t][j].first,dis[i][g[z.t][j].first]});
				}
			}
		}
	}while (q--){
		cin>>x>>y;
		int ans=1e18;
		for (int i=0;i<ve[x].size();i++){
			for (int j=0;j<ve[y].size();j++){
				ans=min(ans,dis[ve[x][i]][ve[y][j]]+w[x]+w[y]+t[x][ma[x][ve[x][i]]]+t[y][ma[y][ve[y][j]]]);
			}
		}cout<<ans<<"\n";
	}return 0;
}
