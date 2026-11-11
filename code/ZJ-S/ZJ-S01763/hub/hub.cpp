#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<queue> 
using namespace std; 
const int N = 1e6 + 5;
long long ans = 1e18,d[N]; 
vector<int>v[N]; 
int n,k,vis[N],vv[N],vvis[N]; 
queue<int>q; 
void bfs() 
{ 
	for(int i = 1;i <= n;i++) d[i] = 1e18,vvis[i] = 0; 
	for(int i = 1;i <= n;i++) if(vis[i]) q.push(i),vvis[i] = 1,d[i] = 0; 
	while(!q.empty()) 
	{ 
		int x = q.front(); q.pop(); 
		for(int y : v[x]) 
		{ 
			if(d[x] + 1 < d[y]) 
			{ 
				d[y] = d[x] + 1; 
				if(!vvis[y]) vvis[y] = 1,q.push(y); 
			} 
		} 
	} 
	long long sum = 0; 
	for(int i = 1;i <= n;i++) sum = max(sum,d[i]); 
	ans = min(ans,sum); 
} 
void dfs1(int x,int cnt,int h) 
{ 
	vis[x] = 1; 
	if(cnt == h) 
	{ 
		bfs(); 
		vis[x] = 0; 
		return; 
	} 
	for(int y : v[x]) if(!vis[y] && !vv[y]) dfs1(y,cnt + 1,h); 
	vis[x] = 0; 
} 
void dfs(int x,int cnt,int h) 
{ 
	for(int y : v[x]) vv[y] = 1; 
	vis[x] = 1; 
	if(cnt == h) 
	{ 
		if(k - h == 0) bfs(); 
		else 
		{ 
			for(int i = 1;i <= n;i++) if(!vv[i] && !vis[i]) dfs1(i,1,k - h); 
		} 
		vis[x] = 0; 
		for(int y : v[x]) vv[y] = 0; 
		return; 
	} 
	for(int y : v[x]) if(!vis[y]) dfs(y,cnt + 1,h); 
	vis[x] = 0; 
	for(int y : v[x]) vv[y] = 0; 
} 
int main() 
{ 
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 
	int cid,T; 
	cin >> cid >> T; 
	while(T--) 
	{ 
		cin >> n >> k; 
		for(int i = 1;i <= n;i++) v[i].clear(); 
		for(int i = 1;i < n;i++) 
		{ 
			int x,y; 
			cin >> x >> y; 
			v[x].push_back(y); 
			v[y].push_back(x); 
		} 
		ans = 1e18; 
		for(int i = 1;i <= k;i++) 
		{ 
			for(int j = 1;j <= n;j++) 
			{ 
				dfs(j,1,i); 
			}
		}
		cout << ans << "\n";
	}
	return 0;
}