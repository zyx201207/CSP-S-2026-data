#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
int c,n,m,d,q;
int w[N],a[N],t[N];
struct node{
	int v,t;
};
vector<node> s[N];
int ans=inf;
bool vis[N];
void dfs(int xx,int en,int sum){
	if(xx==en){
		ans=min(sum,ans);
		return;
	}
	for(node o:s[xx]){
		if(vis[o.v]){
			continue;
		}
		dfs(o.v,en,sum+o.t);
		vis[o.v]=1;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		for(int j=1;j<=k;j++){
			cin>>a[i]>>t[i];
		}
		for(int j=1;j<k;j++){
			node ss;
			ss.t=t[i];
			ss.v=a[i+1];
			s[a[i]].push_back(ss);
			ss.v=a[i];
			s[a[i+1]].push_back(ss);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=inf;
		memset(vis,0,sizeof(vis));
		dfs(x,y,w[x]+w[y]);
		cout<<ans<<"\n";
	}
	return 0;
}/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/

