#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+5;
const int INF=0x3f3f3f3f;
#define pii pair<int,int>
vector<pii> G[MAXN];
int dis[MAXN],vis[MAXN],cnt[MAXN],x[MAXN];
int n,d;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	if(c==11||c==12){
		while(t--){
			cin >> n >> d;
			for(int i=1;i<=n;i++){
				cin >> x[i];
			}		
			d=d/(x[2]-x[1]);
			if(d==0)cout << 0 <<endl;
			else cout << d <<endl;
		}
		return 0;
	}
	while(t--){
		int ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
			G[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)
				{
					G[i].push_back({j,-1});
					G[j].push_back({i,-1});
				}
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			memset(dis,INF,sizeof(dis));
			memset(vis,false,sizeof(vis));
			memset(cnt,0,sizeof(cnt));
			priority_queue<pii> q;
			q.push({0,i});
			dis[i]=0;
			cnt[i]=1;
			while(!q.empty())
			{
				int u=q.top().second;q.pop();
				vis[u]=true;
				for(pair<int,int> e:G[u])
				{
					int v=e.first,w=-e.second;
					if(!vis[v]&&dis[u]+w<dis[v]){
						dis[v]=dis[u]+w;
						cnt[v]=cnt[u];
						q.push({-dis[v],v});
					}
					else if(!vis[v]&&dis[u]+w==dis[v])
						cnt[v]+=cnt[u];
				}
			}
			for(int j=1;j<=n;j++){
				if(cnt[j]==2)ans++;
			}
		}
		cout << ans/2 <<endl;
	}
	return 0;
}//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
