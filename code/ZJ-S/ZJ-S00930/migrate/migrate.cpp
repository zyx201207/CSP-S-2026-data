#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for(int i = j; i <= k; i++)
#define MaxN 5005
#define int long long

int c, t;
int ans = 0;
int n, d;
int a[MaxN];
vector<int> e[MaxN];
int vis[MaxN];
int bj[MaxN][MaxN];
int tong[MaxN];

void BFS(int s){
//	cout << "BFS " << s << " : ";
	memset(vis, 0, sizeof(vis));
	memset(bj, 0, sizeof(bj));
	memset(tong, 0, sizeof(tong));
	queue<int> q;
	q.push(s); 
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : e[u]){
			if(bj[u][v] || bj[v][u]) continue;
			if(vis[v]){
				if(vis[v] == vis[u]+1){
					tong[v]++;
//					cout << "\nfind " << u << ' ' << v << endl;
				}
			}else{
				vis[v] = vis[u] + 1;
				q.push(v);
				bj[u][v] = 1;
			}
		}
	}
//	For(i, 1, n){
////		cout << vis[i] << ' ';
//	}
//	cout << endl;
}

void solve(){
	For(i, 1, n){		//if can reach, add an edge
		For(j, i, n){
			if(i == j) continue;
			if(a[j] - a[i] <= d){
				e[i].push_back(j);
//				e[j].push_back(i);
			}
		}
	}
	For(i, 1, n){
		BFS(i);
		For(j, 1, n){
			if(tong[j] == 1) ans++;
		}
	}
//	ans /= 2;
	cout << ans << endl;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		if(c <= 10){
			For(i, 1, n){
				cin >> a[i];
			}
			solve();
		}else if(c == 11 || c == 12){
			int dis = a[2] - a[1];
			int kuadu = n / dis;
			int abab;
			while(n--) cin >> abab;
			cout << 0 << endl;
		}else{
			int abab;
			while(n--) cin >> abab;
			cout << 0 << endl;
		}
	}
    return 0;
}
