#include <bits/stdc++.h>
using namespace std;
int n,m,c,s,t,x,y,mi,d[1000010];
vector<int> g[1000010];
inline void dfs(const int &k,const int &l){
	d[k]=d[l]+1;
	for (int i:g[k])
		if (i!=l) dfs(i,k);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while (t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);s=0;
		for (int i=1;i<=n;i++)
			if (d[i]>s) s=d[mi=i];
		dfs(mi,0);s=0;
		for (int i=1;i<=n;i++)
			if (d[i]>s) s=d[i];
		cout<<(--s-m-1)/3+1<<'\n';
	}
	return 0;
}
