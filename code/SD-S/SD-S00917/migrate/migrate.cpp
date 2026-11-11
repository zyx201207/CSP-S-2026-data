#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6;
const int inf = 2e18 + 7;

vector<int> e[maxn + 100];
int cnt[maxn + 100];
int a[maxn + 100];
bool vis[maxn + 100];
int key[maxn + 100];
queue<int> q;
int c,t,n,d;
int ans;



void bfs(int st) {
	q.push(st);
//	vis[st] = 1;
	int val = 0;
	while(!q.empty()) {
		int siz = q.size();
		val ++;
		while(siz --) {
			int u = q.front();
//			cout << u << " ";
			q.pop();
			if(vis[u])
				continue;
			vis[u] = true;
			for(int i : e[u]) {
				if(key[i] == inf || key[i] == val) {
					key[i] = val;
					cnt[i] ++;
									
				}
				q.push(i);	
			}
		}

	}
	
	return ;
}

signed main() {
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);	
	
	-
//	freopen("migrate3.in","r",stdin);
//	freopen("migrate3.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin >> c >> t;
	while(t --) {
		cin >> n >> d;
		ans = 0;
		if(n > 5000) {
			for(int i = 1;i <= n;i ++)
				cin >> a[i];
				
			cout << "0\n";
		}
		for(int i = 1;i <= n;i ++) {
			cin >> a[i];
			for(int j = i - 1;j >= 1;j --) {
				if(a[i] - a[j] <= d) {
					e[j].push_back(i);
//					e[i].push_back(j);
				}
			}
		}
		
//		for(int i = 1;i <= n;i ++) {
//			out(i);
//			cout << ":";
//			for(int it : e[i])
//				out(it),cout << " ";
//			cout << '\n';
//		}
//		return 0;
		
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= n;j ++) {
				vis[j] = cnt[j] = 0;
				key[j] = inf;
			} 
			
			while(!q.empty())
				q.pop();
				
			bfs(i);
			for(int j = 1;j <= n;j ++) {
				ans += (cnt[j] == 2);
			}
			
//			cout << i << ":";
//			for(int j = 1;j <= n;j ++)
//				cout << cnt[j] << " ";
//			cout << '\n';
		}
		cout << ans << '\n';
		
		for(int i = 1;i <= n;i ++)
			e[i].clear();
	}


	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
8 3
0 1 2 4 8 10 11 13

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
