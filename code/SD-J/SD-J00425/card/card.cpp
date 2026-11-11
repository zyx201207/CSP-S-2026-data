#include<bits/stdc++.h>
#define pb push_back
#define dgd(x) priority_queue<x, vector<x>, less<x>>
#define endl '\n'
#define int long long
using namespace std;

const int MAXN = 5e5 + 10;
const int MAXM = 3e5 + 10;
int n, m, a[MAXN], ans[MAXM];
int vis[MAXM];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stack<int> st;
	for(int qwq = 1; qwq <= n; qwq++) {
		memset(vis, false, sizeof vis);
		for(int i = qwq; i <= n; i++) {
			if(!vis[a[i]]) {
				vis[a[i]] = true;
				st.push(a[i]);
			} else {
				while(st.top() != a[i]) {
//					cout << st.top();
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
/*
我没招了// 
*/

/*
DFS,BFS:孩子们没考到我
DP:孩子们今年没有我的题
高精度：滚木
字符串：孩子们记得复习我 
数学,位运算：孩子们喜欢CCF出的题吗 
希望是编译器的问题 
最后一年了CCF你给我整这一死出 
*/
