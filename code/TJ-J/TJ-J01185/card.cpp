#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 5e5 + 10;
int a[N];
int cnt[N];
bool vis[N];

int main(){

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int lunci = 1;lunci <= n;lunci++){
		stack<int> s;
		memset(vis, false, sizeof(vis));
		for (int i = lunci;i <= n;i++){
			int k = a[i];
			if (!vis[k]){
				s.push(k);
				vis[k] = true;
				continue;
			}
			while(!s.empty()){
				if (s.top() == k) break;
				int t = s.top();
				vis[t] = false;
				s.pop();
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}

	return 0;
}

