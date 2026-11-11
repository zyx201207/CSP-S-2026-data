#include<bits/stdc++.h>
using namespace std;
vector<int> a[100010];
long long minn;
int b[100010];
void dfs(long long len, int step,int cnt , int &k){
	if(cnt == k){
		minn = min(len,minn);
		return ;
	}
	for(int i = 0; i < a[step].size(); i++){
		if(!b[a[step][i]]){
			b[a[step][i]] = 1;
			dfs(len+1,a[step][i],cnt+1,k);
			b[a[step][i]] = 0;
		}
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	cin >> c >> t;
	for(int i = 1; i <= t; i++){
		int n, k;
		cin >> n >> k;
		for(int j = 1; j < n; j++){
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		minn = 1e18;
		for(int j = 1; j <= n; j++){
			dfs(0,j,1,k);
		}
		cout << minn << endl;
	}
	return 0;
}