#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int n;
ll x[N] , d;
bool arr[300];
vector<int> g[N];
struct node{
	int x , d;
};
bool s_w(int u,int v){
	int cnt = 0;ll w = 0;
	queue<node>q;
	q.push({u,0});
	while(!q.empty()){//n
		node now = q.front();
		int p = now.x;
		q.pop();
		if( p > v)continue;
		if( p == v && (w == now.d || w == 0)){
			w = now.d;
			cnt ++ ;
			if( cnt >= 3)return false;
			continue;
		}
		for(int i=0;i<g[p].size();i++)
			if( g[p][i] <= v)
				q.push({g[p][i],now.d+1});
	}
	if( cnt == 2)return true;
	return false;
}
void solve_bs(){
	for(int i=1;i<=n;i++)g[i].clear();
	int ans = 0;
	for(int i=1;i<=n;i++)//n^2
		for(int j=i+1;j<=n;j++){
			if( x[j] - x[i] <= d)
				g[i].push_back(j);
			else
				break;
		}
	for(int i=1;i<=n;i++)//n^3
		for(int j=i+2;j<=n;j++)
			if( s_w(i,j) )
				ans ++;
	cout << ans << endl;
}
void solveA(ll q){
	if( q <= d && d < 2 * q || q > d){
		cout << 0 << endl;
		return ; 
	}else {
		cout << n - 3 << endl;
		return ;
	}
}
void solveB(){
	ll ans = 0;
	for(int i=1;i<=n;i++){
		if( n - i >= 3)
			ans += n - (i+4-1) + 1;
	}
	cout << ans << endl;
}
void solve(){
	cin >> n >> d;
	ll xx = 0;
	int tA = 1;
	for(int i=1;i<=n;i++)
		cin >> x[i];
	xx = x[2] - x[1];
	for(int i=2;i<=n;i++)
		if( xx == x[i] - x[i-1])
			tA ++;
	if( n <= 20)
		solve_bs();
	else if( tA == n ){
		solveA(xx);
	}else if( d >= x[n] - x[1])
		solveB();
	else
		solve_bs();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t --){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
