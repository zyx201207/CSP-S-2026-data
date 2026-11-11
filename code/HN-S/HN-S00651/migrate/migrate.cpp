#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c, t, n, dis[20005], cnt[20005];
ll d, x[2000005];
bool f[20005];
vector<int> vc[20005];
void bfs(int x){
	queue<int> q;
	memset(f, 0, sizeof f);
	memset(cnt, 0, sizeof cnt);
	memset(dis, 0x3f, sizeof dis);
	q.push(x);
	dis[x] = 0;
	f[x] = 1;
	cnt[x] = 1;
	while(!q.empty()){
		int fr = q.front(); q.pop();
		for(auto i : vc[fr]){
			if(dis[i] == dis[fr] + 1){
				cnt[i] += cnt[fr];
				continue;
			}
			if(dis[i] < dis[fr] + 1) continue;
			dis[i] = dis[fr] + 1;
			cnt[i] = cnt[fr];
			if(f[i]) continue;
			f[i] = 1;
			q.push(i);
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i], vc[i].clear();
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(x[j] - x[i] > d) break;
				vc[i].push_back(j);
			} 
		}
		for(int i = 1; i <= n; i++){
			bfs(i);
			for(int j = i + 1; j <= n; j++)
				if(cnt[j] == 2) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*

想听关于爱的故事吗
把苦痛咽下吧 匆匆忙忙咽下吧
残存之物所结的果实其名为虚妄
——久眯 & 诗岸 & 洛天依《若有比此更浪漫之事》 

*/
