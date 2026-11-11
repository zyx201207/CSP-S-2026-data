#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+7;
int n,m,a[maxn],t[maxn],lst[maxn],s[maxn];
vector<int> g[maxn];
void dfs(int u,int fa){
	s[u]=t[u];
	for(int v : g[u]){
		if(v==fa)continue;
		dfs(v,u);
		s[u]+=s[v];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		t[a[i]]++;
		lst[a[i]]=i;
	}
	for(int i = 1;i<n;i++){
		if(lst[a[i]]==i){
			g[a[i]].push_back(a[i+1]);
			g[a[i+1]].push_back(a[i]);
		}
	}
	dfs(a[n],0);
	for(int i = 1;i<=m;i++)cout << s[i] << " ";
	cout << "\n";
	return 0;
}

