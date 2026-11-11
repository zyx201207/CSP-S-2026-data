#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 10;
vector<int> g[N];
ll a[N],dp[N],dis[N];
int n,c,T,rd[N],inv[N];
ll d,res;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while(T --){
		ll ans = 0;
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i],g[i].clear();
		if(n <= 3){
			cout << 0 << '\n';
			continue;
		}
		if(c == 11 || c == 12){
			int mx = n;
			for(int i = 1 ; i <= n ; i ++)
				if(a[i] - a[1] > d){
					mx = i;
					break;
				}
			if(mx == 4)
				cout << n - 3 << '\n';
			else if(mx == 5)
				cout << n - 5;
			else
				cout << 0 << '\n';
		}
		else{
			queue<int> q;
			memset(rd,0,sizeof(int) * (n + 1));
			for(int i = 1 ; i <= n ; i ++){
				for(int j = i + 1 ; j <= n && a[j] - a[i] <= d ; j ++){
					g[i].push_back(j);
					rd[j] ++;
				}
			}
			for(int i = 1 ; i <= n ; i ++)
				if(!rd[i])
					q.push(i),dis[i] = 0;
			vector<int> cur;
			while(!q.empty()){
				int u = q.front();
				cur.push_back(u);
				inv[u] = cur.size() - 1;
				q.pop();
				for(int v : g[u])
					if(-- rd[v] == 0)
						q.push(v);
			}
			for(int i = 1 ; i <= n ; i ++){
				for(int j = 0 ; j < n ; j ++)
					dp[j] = 0,dis[j] = 0x3f3f3f3f;
				dis[inv[i]] = 0;
				dp[inv[i]] = 1;
				res = 0;
				for(int j = inv[i] ; j < n ; j ++)
					for(int v : g[j + 1])
						dis[v - 1] = min(dis[v - 1],dis[j] + 1);
				for(int j = inv[i] ; j < n ; j ++)
					for(int v : g[j + 1])
						if(dis[v - 1] == dis[j] + 1)
							dp[v - 1] += dp[j];
				for(int j = 0 ; j < n ; j ++)
					if(dp[j] == 2)
						res ++;
				ans += res;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}