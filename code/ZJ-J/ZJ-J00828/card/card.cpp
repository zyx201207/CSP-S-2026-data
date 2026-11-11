#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
vector<int> G[N];
int a[N];
int sz[N];
int num[N];
int b[N];
int n, m;
void dfs(int x, int fa){
	sz[x] = 1;
	for(auto v: G[x]){
		if(v == fa)continue;
		dfs(v, x);
		sz[x] += sz[v];
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = n; i >= 1; i--){
		if(b[a[i]] == 0){
			num[a[i]] = i;
			G[i+1].push_back(i);
		}
		else{
			G[b[a[i]]].push_back(i);
		}
		b[a[i]] = i;
	} 
	dfs(n+1, 0);
	for(int i = 1; i <= m; i++){
		cout << sz[num[i]] << " ";
	}
	return 0;
}
