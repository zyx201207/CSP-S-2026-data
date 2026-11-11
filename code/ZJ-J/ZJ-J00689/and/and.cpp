#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];
long long temp[200005];
bool vis[200005];
long long ans = -1;
long long ain = LLONG_MAX;
long long befo = 0;

void dfs(int dep){
	if(dep == m + 1){
		ans = max(ans,ain);
		return ;
	}
	for(int i = dep; i <= n; i++){
		long long c = a[i];
		if(dep >= 2 && c == a[dep]) continue;
		if(vis[i]) continue;
		temp[dep] = ain;
		ain = ain & c;
		vis[i] = true;
		dfs(dep+1);
		vis[i] = false;
		ain = temp[dep];
	}
	
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	dfs(1);
	
	cout << ans;
	
	
	return 0;
	
}
