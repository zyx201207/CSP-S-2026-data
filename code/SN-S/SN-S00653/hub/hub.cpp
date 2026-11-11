#include<bits/stdc++.h>
#define lint long long
using namespace std;
int c,t,n,k,u,v,ans = 0x3f3f3f3f,dep[200002],f[200002];
vector<int> a[200002];
bool is[200002];
int dfs(int x,int fa,int isroot){
	int sum = 0;
	int l = a[x].size();
	dep[x] = dep[fa] + 1,f[x] = fa;
	for(int _ = 0;_ < l;_++){
		int u = a[x][_];
		if(u == fa) continue;
		if(!is[x] && is[u]) sum += dfs(u,x,1);
		else sum += dfs(u,x,0);
	}
	return sum + isroot;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		ans = 0x3f3f3f3f;
		for(int i = 0;i <= n;i++) a[i].clear();
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int msk = 0;msk < (1 << n);msk++){
			int summmmmm = 0;
			for(int i = 0;i < n;i++) is[i + 1] = bool(msk & (1 << i)),summmmmm += bool(msk & (1 << i));
			if(summmmmm != k) continue;
			dep[0] = 0;
			int cnt = dfs(1,0,is[1]);
			if(cnt > 2) continue;
			int usm = 0;
			for(int i = 1;i <= n;i++){
				if(is[i]) continue;
				int mnnnn = 0x3f3f3f3f;
				for(int j = 1;j <= n;j++){
					if(!is[j]) continue;
					int x = i,y = j,dd = 0;
					if(dep[x] < dep[y]) swap(x,y);
					while(dep[x] > dep[y]) x = f[x],dd++;
					while(x != y) x = f[x],y = f[y],dd += 2;
					mnnnn = min(mnnnn,dd);
				}
				usm = max(usm,mnnnn);
			}
			ans = min(ans,usm);
		}
		cout << ans << "\n";
	}
	return 0;
}
