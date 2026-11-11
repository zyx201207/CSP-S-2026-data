#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
	
int c, n, m, d, p;
int w[N];
int mp[N][N];
int t[N][N];

long long dist[N];
int vis[N];
void work(int x, int y){
	for(int i = 1;i <= m;i ++){
		dist[i] = 1e18;
		vis[i] = 0;
	}
 	dist[x] = 0;
	for(int i = 1;i <= m;i ++){
		int t = -1;
		for(int j = 1;j <= m;j ++){
			if(!vis[j] && (t == -1 || dist[t] > dist[j])){
				t = j;
			}
		}
		vis[t] = 1;
		for(int j = 1;j <= m;j ++){
			if(!vis[j] && dist[j] > dist[t] + mp[t][j]){
				dist[j] = dist[t] + mp[t][j];
			}
		}
	}
	printf("%lld\n", w[x] + w[y] + dist[y]);
	return ;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &p);
	for(int i = 1;i <= m;i ++){
		scanf("%d", &w[i]);
	}
	
	for(int i = 1;i <= n;i ++){
		int k;
		scanf("%d", &k);
		for(int j = 1;j <= m;j ++){
			t[i][j] = 1e8;
		}
		for(int j = 1;j <= k;j ++){
			int a, x;
			scanf("%d%d", &a, &x);
			t[i][a] = x;
		}
	}
	
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= m;j ++){
			mp[i][j] = 1e9;
		}
	}
	
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= m;j ++){
			for(int k = 1;k <= n;k ++){
				mp[i][j] = min(mp[i][j], t[k][i] + t[k][j]);
			}
//			cout << mp[i][j] << " ";
		} 
//		cout << endl;
	}
	
	for(int i = 1;i <= p;i ++){
		int x, y;
		scanf("%d%d", &x, &y);
		work(x, y);
	}
	
	
	return 0; 
}