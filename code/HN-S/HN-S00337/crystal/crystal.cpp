#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+10;
int n, m, data[N], pre[N];

pair<int, int> dfs(int l, int r){
	if(pre[r]-pre[l]-(data[r]-data[l])*(l-1) <= m){
		pair<int, int> u;
		u.first = l;
		u.second = r;
		return u;
	}
	int maxn = 0;
	pair<int, int> u1, u2;
	u1 = dfs(l+1, r);
	//maxn = max((u.second - u.first + 1), maxn);
	u2 = dfs(l, r-1);
	//maxn = max((u.second - u.first + 1), maxn);
	return ((u1.second - u1.first + 1) > (u2.second - u2.first + 1) ? u1 : u2);
} 

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> data[i];
	}
	sort(data+1, data+n+1);
	for(int i = 2; i <= n; i++){
		pre[i] = pre[i-1] + (i-1) * (data[i]-data[i-1]);
	}
	pair<int, int> o = dfs(1, n);
	cout << (o.second - o.first + 1);
	return 0;
} 
