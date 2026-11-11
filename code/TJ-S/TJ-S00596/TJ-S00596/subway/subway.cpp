#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL c,n,m,d,q,k,ans,res,w[500010];
bool vis[510];
vector<int> e[510],t[510];
void dfs(int u,int ed){
	if(u==ed)res=min(res,ans+t[u][0]);
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i],ti=t[u][i];
		if(!vis[v]){
			vis[v]=1;
			ans+=ti;
			dfs(v,ed);
			vis[v]=0;
			ans-=ti;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		int u,v,ut,vt;
		for(int j=1;j<=k;j++){
			cin>>u>>ut;
			if(j!=1){
				e[u].push_back(v);
				e[v].push_back(u);
				t[u].push_back(ut);
				t[v].push_back(vt);
			}
			v=u,vt=ut;
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		ans=w[u]+w[v],res=9e18;
		dfs(u,v);
		cout<<res<<endl;
	}
	return 0;
}
