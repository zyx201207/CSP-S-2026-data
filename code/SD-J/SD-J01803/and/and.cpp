#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2*1e5+5;
ll n,m;
ll a[N];
ll ans = -1;
void dfs(ll c,ll x,ll y){
	if(c == m){
		ans = max(y,ans);
		return ;
	}
	for(int i = x+1;i <= n;++i){
		dfs(c+1,i,y&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	for(int i = 1;i <= n-m;++i){
		dfs(1,i,a[i]);
	}
	cout << ans <<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

