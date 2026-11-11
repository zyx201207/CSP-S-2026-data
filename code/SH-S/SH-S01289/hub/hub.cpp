# include <bits/stdc++.h>
# define MAXN 2000010
using namespace std;
int c,t;
int n,k;
int u,v;
int ans;
int a[MAXN];
vector<int> G[MAXN];
//queue<int> qu;
bool vis[MAXN];

void find(int x,int cnt,int op){
	//qu.push(x);
	cnt++;
	vis[x] = 1;
	for(int k : G[x]){
		if(vis[k]) continue;
		find(x,cnt,op);
	}
	a[op] = max(a[op],cnt);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i = 1; i <= t; i++){
		cin>>n>>k;
		ans = 0x7f;
		memset(a,0,sizeof(a));
		for(int j = 1; j < n; j++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int j = 1; j <= n; j++){
			find(j,0,j);
		}
		for(int j = 1; j <= n; j++){
			ans = min(ans,a[j]);
		}
		cout<<ans;
	}
	return 0;
}
