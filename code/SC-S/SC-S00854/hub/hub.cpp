#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int c,t,vis[N];
vector<int>to[N];
struct edge{
	int ides,x;
};
edge ans[N];
int cmd(edge a,edge b){
	return a.x>b.x;
}
int dfs(int x,int ds,int ans){
	if(vis[x]) return 1;
	int tet=ans+1;
	vis[x]=1;
	for(auto y:to[x]){
		if(y==ds) continue;
		tet=max(dfs(y,ds,tet),tet);
	}
//	cout<<tet<<endl;
	return tet;
}
void solve(){
	int n,k,m=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		ans[i].x=0,vis[i]=0,ans[i].ides=i;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		to[x].push_back(y);
		to[y].push_back(x);
		ans[x].x++;
		ans[y].x++;
	}
	sort(ans+1,ans+n,cmd);
//	for(int i=1;i<=n;i++) cout<<ans[i].ides<<' ';
	for(int i=2;i<=n;i++)
		m=min(dfs(i,ans[1].ides,0),m);
	cout<<m<<endl;
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}