#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//m <= 500005 d <= 20 q <= 100000 
int w[500005];
vector<int> a[501];  
vector<int> t[501];
bool vis[500005];int u,v,an = 1000000;
void dfs(int x,int ans){
	if(x == v)
		an = min(ans,an);
	for(int i = 1;i <= n;i ++){
		if(a[i][0] == x && !vis[a[i][1]]){
			int to = a[i][1];
			vis[to] = 1;
			dfs(to,ans + t[i][1] + t[i][0]);
		}
		if(a[i][1] == x && !vis[a[i][0]]){
			int to = a[i][0];
			vis[to] = 1;
			dfs(to,ans + t[i][1] + t[i][0]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)
		cin >> w[i];
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			int x,y;
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y); 
		}
	}
	while(q --){
		cin >> u >> v;
		an = 1000000;
		memset(vis,0,sizeof(vis));
		dfs(u,w[u] + w[v]);
		cout << an << endl;
	}
	return 0;
} 
