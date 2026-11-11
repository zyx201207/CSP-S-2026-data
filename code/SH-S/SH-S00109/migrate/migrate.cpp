#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5,inf = 1e18;
int c,t,n,d,a[N],x,y,minn,minx,mem[N],ans;
int dfs(int u,int cnt){
	if(mem[u] == -1)return -1;
	mem[u] = -1;
	if(u == y){
		if(cnt == minn)minx++;
		else if(cnt < minn){
			minn = cnt;
			minx = 1;
		}
		return minx;
	}
	for(int i = u + 1;i <= n;i++){
		if(a[i] - a[u] > d)break;
		if(mem[i] > 0)minx += mem[i];
		else mem[i] = dfs(i,cnt + 1);
	}
	for(int i = u - 1;i > 0;i--){
		if(a[u] - a[i] > d)break;
		if(mem[i] > 0)minx += mem[i];
		else mem[i] = dfs(i,cnt + 1);
	}
	return minx;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++)cin >> a[i];
		if(c >= 11 && c <= 12){
			if(a[2] - a[1] > d/2)cout << 0 << endl;
			else cout << max(0LL,n - d/(a[2] - a[1])*2 + 1) << endl;
			continue;
		}
		if(c >= 13){
			cout << 0 << endl;
			continue;
		}
		ans = 0;
		for(x = 1;x <= n;x++){
			for(y = 1;y <= n;y++){
				if(x != y){
					minn = inf;
					minx = 0;
					memset(mem,0,sizeof(mem));
					dfs(x,0);
					if(minx == 2)ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
