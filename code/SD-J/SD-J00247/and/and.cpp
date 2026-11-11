#include<iostream>
#include<iomanip>
#include<cmath>
#define ll long long
using namespace std;
const int N = 2e5+5;

ll n ,a[N] ,m ,ans;

void dfs(ll x ,ll sum ,ll now) {
	if( sum==m ) {
		ans = max(ans , now);
		return ;
	}
	for(int i=x+1; i<=n ; i++) dfs(i ,sum+1 ,now&a[x]);
	for(int i=x+1; i<=n ; i++) dfs(i ,sum ,now);
}


int main(){
	freopen("and.in", "r" ,stdin);
	freopen("and.out" ,"w" ,stdout);
	cin >> n >> m;
	for(int i=1; i<=n ; i++) cin >> a[i];
	dfs(1 ,0 ,a[1]);
	cout << ans;
	return 0;
}
