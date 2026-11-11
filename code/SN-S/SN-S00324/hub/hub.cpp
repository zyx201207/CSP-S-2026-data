//邓洛克 SN-S00324 西安市铁一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,a[15],dep[15],minn,ans;
bool vis[15];
vector<int> vec[15];
void dfs2(int cur){
	vis[cur] = 1;
	for(int i : vec[cur]) if(!vis[i] && a[i]) dfs2(i);
}
void dfs2(int cur,int fa){
	dep[cur] = dep[fa] + 1;
	if(a[cur]) minn = min(minn,dep[cur]);
	for(int i : vec[cur]){
		if(i == fa) continue;
		dfs2(i,cur);
	}
}
void dfs1(int cur,int sum){
	if(cur == n + 1){
		if(sum == k){
			memset(vis,0,sizeof(vis));
			int num = 0,maxx = -1e18;
			for(int i = 1;i <= n;i++) if(a[i] && !vis[i]) dfs2(i),num++;
			if(num > 2) return;
			for(int i = 1;i <= n;i++){
				minn = 1e18;
				dfs2(i,0);
				maxx = max(maxx,minn);
			}
			ans = min(ans,maxx - 1);
		}
		return;
	}
	a[cur] = 1;
	dfs1(cur + 1,sum + 1);
	a[cur] = 0;
	dfs1(cur + 1,sum); 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--){
		ans = 1e18;
		cin >> n >> k;
		for(int i = 1;i <= n;i++) vec[i].clear();
		for(int i = 1,x,y;i < n;i++){
			cin >> x >> y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		dfs1(1,0);
		cout << ans << endl;
	}
	return 0;
}
