#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2010;
const long long M = 1073741823;
LL n,m,a[N];
LL ans = 0;
bool f[N];
void dfs(int k,long long sum){
	if (k == m){
		ans = max(ans,sum);
		return;
	}
	for (int i = 1;i <= n;i++){
		if (f[i]) continue;
		f[i] = 1;
		dfs(k+1,sum & a[i]);
		f[i] = 0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(0,M);
	cout << ans <<"\n";
	return 0;
}

