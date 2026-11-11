#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c, n, m, d, q;
struct node{
	int w;//地铁口 <=> 站厅 的时间 
	int t[505];//t[i] 表示 i 号线中 站厅 <=> 站台 的时间 
}spot[500005];
struct st{
	int id; 
	int type;//所处的线路的编号 
	ll val;
	bool operator <(const st& other)const{
		return other.val < val;
	}
};

vector<st> tt[500005];
ll minn[505];
ll dis[500005];
bool f[500005];

void clean(){
	for (int i = 1; i <= m; i++){
		dis[i] = LLONG_MAX;
		f[i] = 0;
		minn[i] = LLONG_MAX;
	}
}

void search(int start, int final){
	ll tot = LLONG_MAX;
	clean();
	
	priority_queue<st> q;
	for (int i = 1; i <= n; i++){
		if (spot[start].t[i]){
			q.push((st){start, i, spot[start].t[i]});
			minn[i] = spot[start].t[i];
		}
	}
	f[start] = 1;
	dis[start] = 0;
	while (!q.empty()){
		st x = q.top();
		q.pop();
		if (x.id == final){
			tot = min(tot, (ll)spot[start].w + spot[final].w + x.val + spot[final].t[x.type]);
			continue;
		}
		for (int j = 0; j < tt[x.id].size(); j++){
			st xx = tt[x.id][j];
			ll op = 0;
			if (xx.type != x.type){
				op = spot[x.id].t[x.type] + spot[x.id].t[xx.type];
				if (x.id == start){
					op -= spot[x.id].t[x.type];
				}
			} 
			minn[xx.type] = min(minn[xx.type], x.val + op);
			if (dis[xx.id] > x.val + op){
				dis[xx.id] = x.val + op;
				dis[xx.id] = min(dis[xx.id], minn[xx.type]);
			}
			if (!f[xx.id]){
				f[xx.id] = 1;
				q.push((st){xx.id, xx.type, dis[xx.id]});
			}	
		}
	}
	cout << tot << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> spot[i].w;
	}
	
	for (int i = 1; i <= n; i++){
		int k, a[500005], ti;
		cin >> k;
		for (int j = 1; j <= k; j++){
			cin >> a[j] >> ti;
			spot[a[j]].t[i] = ti;
		}
		for (int j = 1; j < k; j++){
			tt[a[j]].push_back((st){a[j + 1], i});
			tt[a[j + 1]].push_back((st){a[j], i});
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		search(x, y);
	}
	return 0;
}
