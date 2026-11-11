#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005 , M = 2e6 + 5;
int c , t , n;
ll d , x[M] , cnt[N] , dis[N] , l[M][2] , r[M][2];
bool vis[N];
vector<int>g[N];
ll read(){
	ll f = 1 , x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f * x;
}
void bfs(int s){
	memset(dis , 0 , sizeof dis);
	memset(cnt , 0 , sizeof cnt);
	memset(vis , false , sizeof vis);
	queue<int>q;
	q.push(s);
	dis[s] = 0;
	cnt[s] = 1;
	vis[s] = true;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i : g[t]){
			if(!vis[i] || dis[t] + 1 == dis[i])cnt[i] += cnt[t];
			if(vis[i])continue;
			dis[i] = dis[t] + 1;
			vis[i] = true;
			q.push(i);
		}
	}
}
void sol(){
	n = read(); d = read();
	for(int i = 1;i <= n;i++)x[i] = read();
	if(c >= 0 && c <= 10){
		for(int i = 1;i <= n;i++)g[i].clear();
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(x[j] - x[i] <= d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for(int i = 1;i <= n;i++){
			bfs(i);
			for(int j = i + 1;j <= n;j++){
				if(cnt[j] == 2)ans++;
			}
		}
		cout << ans << '\n';
		return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)sol();
	return 0;
} 
