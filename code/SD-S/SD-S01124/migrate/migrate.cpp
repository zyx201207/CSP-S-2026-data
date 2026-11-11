#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int c,t,dis[N];
vector <int> g[N];
bool vis[N];
int cnt[N];
long long ans;
inline pair<int,int> pii(int a,int b){
	pair<long long,int> ttt;
	ttt.first = a,ttt.second = b;
	return ttt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;scanf("%d%d",&n,&d);
		long long x[N];
		for (int i = 1;i <= n;i++) g[i].clear();
		ans = 0;
		for (int i = 1;i <= n;i++){
			scanf("%lld",&x[i]);
		}for (int i = 1;i <= n;i++){
			for (int j = i + 1;j <= n;j++){
				if(abs(x[i] - x[j]) <= d){
					g[i].push_back(j),g[j].push_back(i);
				} 
			}
		}for (int i = 1;i <= n;i++){
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			memset(cnt,0,sizeof(cnt));
			queue <int> q;
			q.push(i);
			dis[i] = 0,vis[i] = 1;
			while(!q.empty()){
				int u = q.front();q.pop();
				int len = g[u].size();
				for (int i = 0;i < len;i++){
					int v = g[u][i];
					if(vis[v]){
						if(dis[v] == dis[u] + 1) cnt[v]++;
					}else{
						cnt[v]++;
						vis[v] = 1;
						dis[v] = dis[u] + 1;
						q.push(v);
					}
				}
			}for (int j = i + 1;j <= n;j++)
				ans += (cnt[j] == 2);
		}printf("%lld\n",ans);
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
