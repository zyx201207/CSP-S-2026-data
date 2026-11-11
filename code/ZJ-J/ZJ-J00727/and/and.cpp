#include <bits/stdc++.h>
using namespace std;
long long m,n,sum;
long long a[200005];
void dfs(long long x,long long ans,long long k){
//	cout << x << ' ' << ans << endl;
	if(x == m){
		if(sum < ans) sum = ans;
		return;
	}
	if(x > m) return;
	if(k > n) return;
	for(long long i = k;i <= n;i++){
		if(x == 0) dfs(1,a[i],i + 1);
		else dfs(x + 1,ans & a[i],i + 1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dfs(0,0,1);
	cout << sum;
	return 0;
}