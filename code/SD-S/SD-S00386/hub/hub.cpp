#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2,inf = 1e9;
int n,k,ans = inf;

struct node{
	vector<int> v;
	int b = 0,sq = 0,d = -1;
}a[N];

int bfs(int p){
	int ok = 1;
	for(int i = 1;i <= n;i++){
		if(i == 2||i == 7||i == 9){
			if(!a[i].b) ok = 0;
		}else if(a[i].b) ok = 0;
	}
//	if(ok) cout << "yaxc";
	for(int i = 1;i <= n;i++) a[i].d = 0;
	queue<pair<int,int> > bq;
	bq.push({p,0});
	while(!bq.empty()){
		auto k = bq.front();
		bq.pop();
		a[k.first].d = 1;
		if(a[k.first].b){
//			if(ok) cout << k.second << ' ';
			return k.second;
		}
		for(int i : a[k.first].v){
			if(!a[i].d){
				bq.push({i,k.second + 1});
			}
		}
	}
//	cout << 1;
}

int find(int x){
	if(a[x].b){
		if(a[x].sq) return 0;
		a[x].sq = 1;
		for(int i : a[x].v){
			if(!a[i].sq) find(i);
		}
		return 1;
	}
	return 0;
}

bool check(){
	for(int i = 1;i <= n;i++){
		a[i].sq = 0;
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		int k = find(i);
		cnt += k;
	}
//	if(a[2].b&&a[3].b&&a[10].b) cout << cnt;
	if(cnt > 2) return false;
	return true;
}

void dfs(int c,int b){
	if(b > k||k - b > n - c + 1) return;
	if(c == n + 1){
		if(b != k) return;
		if(!check()) return;
		int tans = -1;
		for(int i = 1;i <= n;i++){
			tans = max(tans,bfs(i));
		}
//		if(n == 10&&tans == 1){
//			for(int i = 1;i <= n;i++) if(a[i].b) cout << i << ' ';
//			cout << '\n';
//		}
//		if(n == 10) cout << ans << ' ';
		ans = min(ans,tans);
		return;
	}
	dfs(c + 1,b);
	a[c].b = 1;
	dfs(c + 1,b + 1);
	a[c].b = 0;
	return;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		ans = inf;
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			a[i].v.clear();
			a[i].b = a[i].sq = 0;
		}
		for(int i = 1;i < n;i++){
			int x,y;
			cin >> x >> y;
			a[x].v.emplace_back(y);
			a[y].v.emplace_back(x);
		}
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
}
