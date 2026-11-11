#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
long long x[N];
int cnt[N];
int dis[N];
int n,d;

void dfs(int u,int step){
	if (step < dis[u]){
		dis[u] = step;
		cnt[u] = 1;
	}
	else if(step == dis[u]){
		cnt[u]++; 
	}
	for (int v = u + 1; v <= n; v++){
		if (x[v] - x[u] <= d){
			dfs(v,step+1);
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> x[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			memset(dis,0x3f,sizeof dis);
			dfs(i,0);
			for (int j = 1; j <= n; j++){
				if (cnt[j] == 2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
