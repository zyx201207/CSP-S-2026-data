#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N = 505;
const LL M = 5e5 + 10;
const LL D = 10;
//bool f1;
LL c, n, m, d, q, k, x, y;
LL dis[M], w[M], ans;
vector<LL> tr[N];
bool vis[M];

struct Node{
	LL idx, t;
};

vector<LL> line[M];
//vector<Node> sta[M];
map<LL, LL> sta[N];
//bool f2;
//void dfs(LL pos, LL Line, LL dis){
//	if(pos == y){
//		ans = min(ans, dis + w[x] + sta[Line][y] + w[y]);
//		return;
//	}
//	vis[pos] = true;
//	if(pos == x){
//		LL pre = 0, nxt = 0;
//		for(LL j = 0; j < tr[Line].size(); j++){
//			if(tr[Line][j] == pos){
//				if(j)
//					pre = tr[Line][j - 1];
//				if(j + 1 < tr[Line].size())
//					nxt = tr[Line][j + 1];
//				break;
//			}
//		}
//		if(!vis[pre]){
//			dfs(pre, Line, dis);
//			vis[pre] = false;
//		}
//			
//		if(!vis[nxt]){
//			dfs(nxt, Line, dis);
//			vis[nxt] = false;
//		}
//			
//		return;
//	}
//	for(auto i : line[pos]){
//		LL trans = 0;
//		if(i != Line){
//			trans += sta[i][pos] + sta[Line][pos];
//		}
//		LL pre = 0, nxt = 0;
//		for(LL j = 0; j < tr[i].size(); j++){
//			if(tr[i][j] == pos){
//				if(j)
//					pre = tr[i][j - 1];
//				if(j + 1 < tr[i].size())
//					nxt = tr[i][j + 1];
//				break;
//			}
//		}
//		if(!vis[pre]){
//			dfs(pre, i, dis);
//			vis[pre] = false;
//		}
//		if(!vis[nxt]){
//			dfs(nxt, i, dis);
//			vis[nxt] = false;
//		}
//	}
//}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	cout << abs(&f1 - &f2) / 1024.0 / 1024.0 << '\n';
	cin >> c >> n >> m >> d >> q;
	for(LL i = 1; i <= m; i++)	cin >> w[i];
	for(LL i = 1; i <= n; i++){
		cin >> k;
//		LL pre = 0;
		for(LL j = 1; j <= k; j++){
			LL ind, time;
			cin >> ind >> time;
			sta[i][ind] = time;
			line[ind].push_back(i);
			tr[i].push_back(ind);
//			pre = ind;
//			dis[tr[i][j - 1]][tr[i][j]][i] += time;
		}
	}
	while(q--){
//		LL x, y;
		cin >> x >> y;
		priority_queue<pair<LL, pair<LL, LL>>> pq;
		ans = LONG_LONG_MAX;
		for(auto k : line[x]){
//			memset(vis, 0, sizeof vis);
//			cout << 1 << '\n';
			memset(dis, 0x7f, sizeof dis);
			while(!pq.empty())	pq.pop();
			pq.push(make_pair(sta[k][x], make_pair(x, k)));
			dis[x] = sta[k][x];
			dis[0] = 0;
			while(!pq.empty()){
				pair<LL, pair<LL, LL>> cur = pq.top();
				pq.pop();
				for(LL i : line[cur.second.first]){
					LL trans = 0;
					if(i != cur.second.second)
						trans += sta[cur.second.second][cur.second.first] + sta[i][cur.second.first];
					LL pre = 0, nxt = 0;
					for(LL j = 0; j < tr[i].size(); j++){
						if(tr[i][j] == cur.second.first){
							if(j)
								pre = tr[i][j - 1];
							if(j + 1 < tr[i].size())
								nxt = tr[i][j + 1];
							break;
						}
					}
					if(pre == y){
						if(dis[pre] > dis[cur.second.first] + trans + sta[i][y]){
							dis[pre] = dis[cur.second.first] + trans + sta[i][y];
//							pq.push(make_pair(dis[pre], make_pair(pre, i)));
						}
					}
					else{
						if(dis[pre] > dis[cur.second.first] + trans){
							dis[pre] = dis[cur.second.first] + trans;
							pq.push(make_pair(dis[pre], make_pair(pre, i)));
						}
					}
					if(nxt == y){
						if(dis[nxt] > dis[cur.second.first] + trans + sta[i][y]){
							dis[nxt] = dis[cur.second.first] + trans + sta[i][y];
//							pq.push(make_pair(dis[nxt], make_pair(nxt, i)));
						}
					}
					else{
						if(dis[nxt] > dis[cur.second.first] + trans){
							dis[nxt] = dis[cur.second.first] + trans;
							pq.push(make_pair(dis[nxt], make_pair(nxt, i)));
						}
					}
				}
			}
			ans = min(ans, dis[y] + w[x] + w[y]);
//			dfs(x, k, sta[k][x]);
//			cout << 1 << '\n';
		}
			
		cout << ans << '\n';
	}
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
