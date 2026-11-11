#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

vector<long long> a[1000010];
long long bj[110];
long long d[110];
long long vis[110];
long long f[110];
long long n, k;
long long c = INF;

void dfs(long long x){
	if(bj[x] == 0 || vis[x] == 1) return;
	vis[x] = 1;
	for(long long i = 0; i < a[x].size(); i++){
		long long v = a[x][i];
		dfs(v);
	}
	return;
}

void dfs3(long long x, long long g){
	f[x] = min(f[x], f[g] + 1);
	for(long long i = 0; i < a[x].size(); i++){
		long long v = a[x][i];
		if(v == g) continue;
		dfs3(v, x);
	}
	return;
}

void dfs2(long long x){
	if(x == n){
		long long l = 0;
		for(long long i = 1; i <= n; i++){
			l += bj[i];
			vis[i] = 0;
			f[i] = INF;
		}
		if(l != k) return;
		l = 0;
		for(long long i = 1; i <= n; i++){
			if(bj[i] == 0) continue;
			if(vis[i] == 0){
				l++;
				dfs(i);
			}
		}
		if(l > 2) return;
		long long v = 0;
		for(long long i = 1; i <= n; i++){
			if(bj[i] == 0) continue;
			f[i] = 0;
			dfs3(i, i);
		}
		for(long long i = 1; i <= n; i++){
			vis[i] = 0;
			v = max(v, f[i]);
		}
		c = min(c, v);
		return;
	}
	x++;
	bj[x] = 1;
	dfs2(x);
	bj[x] = 0;
	dfs2(x);
	return;
}

void dfs4(long long x, long long g){
	d[x] = d[g] + 1;
	for(long long i = 0; i < a[x].size(); i++){
		long long v = a[x][i];
		if(v == g) continue;
		dfs4(v, x);
	}
	return;
}

void sl(){
	c = INF;
	cin >> n >> k;
	for(long long i = 0; i <= n; i++) a[i].clear();
	for(long long i = 1; i < n; i++){
		long long x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if(k == 2){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				bj[i] = 1;
				bj[j] = 1;
				for(long long i = 1; i <= n; i++){
					vis[i] = 0;
					f[i] = INF;
				}
				for(long long i = 1; i <= n; i++){
					if(bj[i] == 0) continue;
					if(vis[i] == 0){
						dfs(i);
					}
				}
				long long v = 0;
				for(long long i = 1; i <= n; i++){
					if(bj[i] == 0) continue;
					f[i] = 0;
					dfs3(i, i);
				}
				for(long long i = 1; i <= n; i++){
					vis[i] = 0;
					v = max(v, f[i]);
				}
				c = min(c, v);
				bj[i] = 0;
				bj[j] = 0;
			}
		}
		cout << c << endl;
		return;
	}
	dfs2(0);
	cout << c << endl;
	return;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	long long bh, sj;
	cin >> bh >> sj;
	while(sj--){
		sl();
	}




	return 0;
}
