#include <bits/stdc++.h>
using namespace std;
//check long long check unvoid 

//int tag[2000005];
int n;
int addcnt;
long long D, a[2000005], ans;
int nxt[2000005];
vector<int> g[2000005];

//void Add(int l, int r, int op){
//	if(l > r) return ;
//	for(int i = l; i <= r; i++) tag[i] += op;
//}

struct node{
	int minn, minnn, minncnt, minnncnt, tag;
}tree[2000005 << 2];

void upd(int &minn, int &cnt, int v, int c){
	if(minn > v){
		minn = v; cnt = c;
	} else if(v == minn){
		cnt += c;
	}
}

void push_up(int u){
	tree[u].minncnt = tree[u].minnncnt = 0;
	tree[u].minn = tree[u].minnn = (int)1e9;
	
	upd(tree[u].minn, tree[u].minncnt, tree[u << 1].minn, tree[u << 1].minncnt);
	upd(tree[u].minn, tree[u].minncnt, tree[u << 1 | 1].minn, tree[u << 1 | 1].minncnt);
	
	if(tree[u].minn != tree[u << 1].minn) upd(tree[u].minnn, tree[u].minnncnt, tree[u << 1].minn, tree[u << 1].minncnt);
	else upd(tree[u].minnn, tree[u].minnncnt, tree[u << 1].minnn, tree[u << 1].minnncnt);
	
	if(tree[u].minn != tree[u << 1 | 1].minn) upd(tree[u].minnn, tree[u].minnncnt, tree[u << 1 | 1].minn, tree[u << 1 | 1].minncnt);
	else upd(tree[u].minnn, tree[u].minnncnt, tree[u << 1 | 1].minnn, tree[u << 1 | 1].minnncnt);
}

void build(int u, int l, int r){
	tree[u].tag = 0;
	if(l == r){
		tree[u].minn = 0;
		tree[u].minnn = (int)1e9;
		tree[u].minncnt = 1;
		tree[u].minnncnt = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	push_up(u);
}

void Tag(int u, int val){
	tree[u].minn += val;
	tree[u].minnn += val;
	tree[u].tag += val;
}

void push_down(int u){
	if(tree[u].tag){
		Tag(u << 1, tree[u].tag);
		Tag(u << 1 | 1, tree[u].tag);
		tree[u].tag = 0;
	}
}

void Add(int u, int l, int r, int L, int R, int val){
	if(L <= l && r <= R){
		Tag(u, val);
		return ;
	}
	int mid = (l + r) >> 1;
	push_down(u);
	if(L <= mid) Add(u << 1, l, mid, L, R, val);
	if(mid < R) Add(u << 1 | 1, mid + 1, r, L, R, val);
	push_up(u);
}

void update(int x, int y, int mx, int op){
	x = nxt[x];
	if(y < x){
		if(x == nxt[y]){
			if(y < mx){
//				addcnt++;
				Add(1, 1, n, y + 1, mx, op);
			}
			return ;
		}
//		addcnt++;
		Add(1, 1, n, y + 1, x, op);
	}
	y = nxt[y];
	
	if(x + 2 <= y) return ;
	if(nxt[x - 1] == nxt[x]) return ;
	
	x = nxt[x];
	if(y < x){
		if(x == nxt[y]){
			if(y < mx){
//				addcnt++;
				Add(1, 1, n, y + 1, mx, op);
			}
			return ;
		}
//		addcnt++;
		Add(1, 1, n, y + 1, x, op);
	}
	y = nxt[y];
}

void DFS(int x, int mx){
//	if(nxt[nxt[x]]){
//		if(nxt[x] - 1 > x) update(nxt[x] - 1, nxt[x], mx, 1);
//		if(nxt[x] - 2 > x) update(nxt[x] - 2, nxt[x], mx, 1);
//	}
	
//	assert(tree[1].minn == 0);
	if(tree[1].minnn == 1){
		ans += tree[1].minnncnt;
	}
	reverse(g[x].begin(), g[x].end());
//	for(int i = x; i <= mx; i++) if(tag[i] == 1) ans++;
	bool opa = 0, opb = 0;
	for(auto it : g[x]){
		if(nxt[x]){
			if(it < x - 1 && !opa){
				update(x - 1, x, mx, 1);
				opa = 1;
			}
			if(it < x - 2 && !opb){
				update(x - 2, x, mx, 1);
				opb = 1;
			}
		}
		DFS(it, mx);
	}
	
//	if(nxt[nxt[x]]){
//		if(nxt[x] - 1 > x) update(nxt[x] - 1, nxt[x], mx, -1);
//		if(nxt[x] - 2 > x) update(nxt[x] - 2, nxt[x], mx, -1);
//	}
	if(opa) update(x - 1, x, mx, -1);
	if(opb) update(x - 2, x, mx, -1);
}

void get_ans(int l, int r){
	if(l == r) return ;
	
	{
		int j = l;
		for(int i = l; i <= r; i++){
			while(j < r && a[j + 1] - a[i] <= D) j++;
			nxt[i] = j;
		}
		nxt[r] = 0;
		
		for(int i = l; i < r; i++) g[nxt[i]].push_back(i);
	}
	
	DFS(r, r);
}
void solve(){
	ans = 0;
	cin >> n >> D;
	for(int i = 1; i <= n; i++){
		g[i].clear();
//		tag[i] = 0;
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	build(1, 1, n);
	
	for(int i = 1; i <= n;){
		int j = i;
		while(j < n && a[j + 1] - a[j] <= D) j++;
		
		get_ans(i, j);
		i = j + 1;
	}
	cout << ans << "\n";
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c, t;
	cin >> c >> t;
	while(t--) solve();
//	cout << addcnt << endl;
//	cout << (double)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
