#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000001];
vector<int> e[2000001];
int dis[2000001];
vector<int> nxt[2000001];
ll f[2000001];
void bfs(int s){
	queue<int> q;
	q.push(s);
	dis[s] = 1;
	while(!q.empty()){
		int now = q.front();q.pop();
		for(int i : e[now]){
			if(i==now) continue;
			if(dis[i]==1e9||dis[i]==dis[now]+1){
				nxt[now].push_back(i);
				if(dis[i]==1e9){
					q.push(i);
					dis[i] = dis[now]+1;
				}
			}
		}
	}
}
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin >> C >> T;
	while(T--){
		ll n,d;
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i];
		}
		for(int i = 1 ; i <= n ; i++){
			dis[i] = 1e9;
			for(int j = i+1 ; j <= n ; j++){
				if(a[j]-a[i]>d) break;
				e[i].push_back(j);
			}
		}
		ll ans = 0;
		for(int i = 1 ; i <= n ; i++){
			bfs(i);
			f[i] = 1;
			for(int j = i ; j <= n ; j++){
				if(f[j]==2) ans++;
				for(int k : nxt[j]){
					f[k] += f[j];
				}
				f[j] = 0;
				nxt[j].clear();
				dis[j] = 1e9;
			}
		}
		cout << ans << '\n';
		for(int i = 1 ; i <= n ; i++) e[i].clear();
	}
	return 0;
}

