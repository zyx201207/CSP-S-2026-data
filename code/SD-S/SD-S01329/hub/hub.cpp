#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y,d[1000009],f[39][1000009],u[1000009];
vector <int> v[1000009]; 
bitset <1000009> b;
void dfss(int x,int fa){
	f[0][x] = fa,d[x] = d[fa] + 1;
	for(int u : v[x]){
		if(u == fa)continue;
		dfss(u,x);
	}
}
int lac(int x,int y){
	if(x == y)return x;
	for(int i = 0;;i++){
		if(f[i][x] == f[i][y]){
			if(i == 0){
				return f[i][x];
			}
			return lac(f[i - 1][x],f[i - 1][y]);
		}
	}
}
int lca(int x,int y){
	if(d[x] > d[y]){
		swap(x,y);
	}
	int l = d[x] - d[y];
	for(int i = 0;i < 30;i++){
		if((l >> i) & 1){
			x = f[i][x];
		}
	}
	return lac(x,y); 
}
int dfs(int kk){
	int cnt = 1e9;
	if(kk == k + 1){
		for(int i = 1;i <= n;i++){
			u[i] = 1e9;
		}
		for(int i = 1;i <= n;i++){
			if(b[i]){
				for(int j = 1;j <= n;j++){
					u[j] = min(u[j],d[i] + d[j] - d[lca(i,j)] * 2);
				}
			}
		}
		cnt = 0;
		for(int i = 1;i <= n;i++){
			cnt += u[i];
		} 
		return cnt;
	}
	for(int i = 1;i <= n;i++){
		if(!b[i]){
			b[i] = 1;
			cnt = min(cnt,dfs(k + 1));
			b[i] = 0;
		}
	}
	return cnt;
}
int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			v[i].clear();
		}
		for(int i = 1;i < n;i++){
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfss(1,0);
		for(int i = 1;i < 30;i++){
			for(int j = 1;j <= n;j++){
				f[i][j] = f[i - 1][f[i - 1][j]];
			} 
		}
		cout << dfs(1) << '\n';
	}
	return 0;
}
