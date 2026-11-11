#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int a[N];
int dist[N];
bool st[M];
bool flag[N];
stack<int> stk;
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	
	int cnt = 0, t = n;
	while(n --){
		cnt ++;
		// cout << m << endl;
		memset(st, false, sizeof st);
		for(int i = cnt; i <= n; i ++){
			if(st[i] == false){
				stk.push(a[i]);
				st[i] = true;
			}
			else
			{
				while(stk.top() != a[i]){
					st[stk.top()] = false;
					stk.pop();
				}
				st[stk.top()] = false;
				stk.pop();
				stk.push(a[i]);
				st[a[i]] = true;
			}
		}
		// cout << "%" << endl;
		while(!stk.empty()){
			dist[stk.top()] ++;
			stk.pop();
			// cout << "$" << endl;
		}
		// for(int i = 1; i <= m; i ++) cout << dist[i] << endl;
	}
	// cout << "%" << endl;
	for(int i = 1; i <= m; i ++){
		if(flag[a[i]] == false){
			cout << dist[a[i]] << " ";
			flag[a[i]] = true;
		}
	}
	
	return 0;
}
