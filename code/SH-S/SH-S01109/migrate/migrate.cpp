#include<bits/stdc++.h>

// expected: 16pts

using namespace std;

int c;
long long mn=1e9, mn_c;
bool vis[30];
void dfs(long long n, long long d, long long p, long long step, long long t, vector<long long> &x){
	if(vis[p] || step > mn) return;
	vis[p] = 1;
	if(p == t){
		if(step == mn) mn_c ++;
		else if(step < mn) mn = step, mn_c = 1;
		vis[p] = 0;
		return;
	}
	for(int i = p+1; i <= n; i ++){
		if(x[i]-x[p] > d) break;
		dfs(n,d,i,step+1,t,x);
	}
	for(int i = p-1; i >= 1; i --){
		if(x[p]-x[i] > d) break;
		dfs(n,d,i,step+1,t,x);
	}
	vis[p] = 0;
}
long long solve(long long n, long long d, vector<long long> &x){
	if(c == 11 || c == 12){
		long long D = x[2]-x[1];
		d = d/D;
		if(d <= 1) return 0;
		return max(1ll*n+1-2*d,0ll);
	}
	// init
	memset(vis,0,sizeof vis);
	mn = 1e9, mn_c = 0;
	//
	long long ans = 0;
	for(int u = 1; u < n; u ++) for(int v = u+1; v <= n; v ++){
		memset(vis,0,sizeof vis);
		mn = 1e9, mn_c = 0;
		dfs(n,d,u,0,v,x);
		if(mn_c == 2){
			ans ++;
//			cout << u << ' ' << v << ' ' << mn << '\n';
		}
	}
	return ans;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int T; cin >> c >> T;
	while(T --){
		long long n; cin >> n;
		long long d; cin >> d;
		vector<long long> x(n+5);
		for(int i = 1; i <= n; i ++)
			cin >> x[i];
		cout << solve(n,d,x) << '\n';
	}
	
	return 0;
}
