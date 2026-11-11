#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005;
int n, m;
int a[N];
int maxx = -2e9;
void dfs(int now,int cnt,int ans){
	if(ans < maxx) return;
	if(n - now + 1 + cnt < m)return ;
	if(cnt == m){
		maxx = max(maxx,ans);
		return ;
	}
	if(now > n) return ;
	dfs(now + 1,cnt,ans);
	dfs(now + 1,cnt + 1,ans & a[now]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			maxx = max(maxx,a[i]);
		}
		cout << maxx;
	}else if(m == n){
		maxx = a[1];
		for(int i = 2;i <= n;i++){
			maxx = maxx & a[i];
		}
		cout << maxx;
	}else if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				int t = a[i] & a[j];
				maxx = max(maxx,t);
			}
		}
		cout << maxx;
	}else{
		dfs(2,0,0);
		dfs(2,1,a[1]);
		cout << maxx;
	}
	return 0;
}



