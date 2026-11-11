#include<bits/stdc++.h>
#define def(i,a,b) for(i32 i = a;i <= b;i ++)
#define udef(i,a,b) for(i32 i = a;i >= b;i --)
#define Max(a,b) (a = max(a,b))
#define Min(a,b) (a = min(a,b))
#define fi first
#define se second
using namespace std;
using i32 = long long;
using i63 = long long;
const i63 N = 5e5 + 5,INF = 4e18,mod = 998244353;
i32 n,k,x,y;
i32 dep[N];
bool vis[21][21];
i32 f[N][32];
vector<i32> a[N];
void dfs(i32 i,i32 fa){
	dep[i] = dep[fa] + 1;
	f[i][0] = fa;
	def(j,1,20) f[i][j] = f[f[i][j - 1]][j - 1];
	for(i32 j : a[i]){
		if(j == fa) continue;
		dfs(j,i);
	}
}
i32 lca(i32 x,i32 y){
	if(dep[x] < dep[y]) swap(x,y);
	udef(i,20,0) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	udef(i,20,0) if(f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	return f[x][0];
}
i32 get(i32 x,i32 y){
	i32 lc = lca(x,y);
	if(dep[x] < dep[y]) swap(x,y);
	if(y == lc) return dep[x] - dep[y];
	return dep[x] + dep[y] - dep[lc] * 2ll;  
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	i32 c,_;
	cin >> c >> _;
	while(_--){
		i32 ans = INF;
		cin >> n >> k;
		if(n > 10){
			cout << 1 << '\n';
			continue;
		}
		def(i,1,n) a[i].clear();
		def(i,1,n) def(j,1,n) vis[i][j] = 0;
		def(i,1,n - 1){
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
			vis[x][y] = 1;
			vis[y][x] = 1;
		}
		dfs(1,0);
		i32 full = (1 << n) - 1;
		def(i,1,full){
			i32 cnt = 0,t = 0,res = 0;
			vector<i32> p;
			def(j,1,n){
				if(i & (1 << (j - 1))) p.push_back(j);
			}
			if(p.size() != k) continue;
			t = p.size() - 1;
			def(j,0,t){
				bool f = 1;
				i32 t = INF;
				def(k,0,j - 1) {
					if(vis[p[k]][p[j]] || vis[p[j]][p[k]] ) f = 0;
					Min(t,get(p[j],p[k]));
				}
				Max(res,t);
				cnt += f;
			}
			if(cnt <= 2) Min(ans,res);
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
看一下 代码与实际用途是否一致 如缩点后应使用缩点后的图b[i]
注意手打hack对拍 然后对症下要特判
谨防RE 队列一定要判非空 一定要判边界
没事别全开 long long
该break时别continue
备份备份 别一顿乱搞后该不如之前的
部分分 部分分
算一下会不会MLE
*/

