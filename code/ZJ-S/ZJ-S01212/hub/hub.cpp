#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long Int;

const Int N = 1005;
const Int INF = 1145141919810;
Int c, T, n, k, u, v, dis[N], ans;
bool isk[N], vstd[N], vis[N];
vector<Int> og[N];
Int q[N], ql, qr;

void dfs(Int now) {
	vis[now] = 1;
	for (Int x : og[now]) {
		if (!vis[x] && isk[x]) dfs(x);
	}
}

Int dfs1111() {
	memset(vis, 0, sizeof(vis));
	Int cnt = 0;
	for (Int i = 1; i <= n; i++)
		if (isk[i] && !vis[i]) {
			dfs(i);
			cnt++;
		}	
	return cnt;
}

bool isok() {
	Int cnt = 0;
	for (Int i = 1; i <= n; i++) cnt += isk[i];
	if (cnt != k) return 0;
	
	if (dfs1111() > 2) return 0;
	return 1;
}

Int bfsto(Int i) {
	memset(dis, 0, sizeof(dis));
	memset(vstd, 0, sizeof(vstd));
	ql = qr = 1;
	dis[i] = 0;
	Int now;
	q[qr++] = i;
	while (1) {
		now = q[ql++];
		vstd[now] = 1;
		if (isk[now]) break;
		for (Int x : og[now])
			if (!vstd[x]) {
				dis[x] = dis[now]+1;
				q[qr++] = x;
			}
	}
	//cout << "The " << i << " position answer is " << dis[now] << endl;
	return dis[now];
}

Int check() {
	Int mi = 0;
	for (Int i = 1; i <= n; i++) mi = max(mi, bfsto(i));
	return mi;	
}

void find_k(Int i) {
	if (i == n+1) {
		if (!isok()) return;
//		cout << "-----------------try the seg at ";
//		for (Int i = 1; i <= n; i++) cout << isk[i];
//		cout << " , we find " << dfs1111() << "blocks" << endl;
		
		
		ans = min(ans, check());
//		
//		cout << " receiving the answer of " <<  ans<<endl << endl;
		return;
	}
	isk[i] = 1;
	find_k(i+1);
	isk[i] = 0;
	find_k(i+1);
}

void case1() {
	cin >> n >> k;
	for (Int i = 1; i <= 100; i++) {
		og[i].clear();
	}
	for (Int i = 1; i <= n-1; i++) {
		cin >> u >> v;
		og[u].push_back(v);
		og[v].push_back(u);
	}
	
	ans = INF;
	find_k(1);
	
	cout << ans << endl;
}

int main() {
	if (1) {
		freopen("hub.in", "r", stdin);
		freopen("hub.out", "w", stdout);
	}
	
	cin >> c >> T;
	while (T--) {
		if (c <= 3) case1();
		else cout << n/(2+k);
	}
	
	return 0;
}

// baoli for 12pts maybe
