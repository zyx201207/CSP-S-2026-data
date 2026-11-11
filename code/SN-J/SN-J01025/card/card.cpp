#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], dot[N];
bool vis[N];
deque<int>que;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		memset(vis,0,sizeof(vis));
		while(!que.empty()){
			que.pop_front();
		}
		for(int j = i; j <= n; ++j){
			if(vis[a[j]] == true){
				while(que.front() != a[j]){
					vis[que.front()] = false;
					que.pop_front();
				}
			}else{
				vis[a[j]] = true;
				for(int k = 1; k <= m; ++k){
					if(vis[k] == true){
						dot[k]++;
					}
				}
			}
		}
	}
	for(int i = 1; i <= m; ++i){
		cout << dot[i] << '\n';
	}
	return 0;
}

