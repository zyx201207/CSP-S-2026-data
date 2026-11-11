#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans,a[2000010],dis[5010],vis[5010],s,tot;
vector<int> g[5010];
void dfs(int u,int st,int tar){
	if(u==tar){
		ans=min(ans,st);
		return ;
	}
	vis[u]=1;
	for(int v=0;v<g[u].size();v++){
		if(!vis[g[u][v]]){
			dfs(g[u][v],st+1,tar);
			vis[g[u][v]]=0;
		}
	}
}
void dfs2(int u,int st,int tar){
	if(u==tar){
		if(st==ans)s++;
		return ;
	}
	vis[u]=1;
	for(int v=0;v<g[u].size();v++){
		if(!vis[g[u][v]]){
			dfs2(g[u][v],st+1,tar);
			vis[g[u][v]]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		tot=0;
		cin>>n>>d;
		if(n<=3){
			cout<<"0\n";
			continue;
		}
		if(c>4){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				g[i].clear();
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d)g[i].push_back(j);
					else break;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=n;k++)vis[k]=0;
					ans=1e18;
					dfs(i,0,j);
					for(int k=1;k<=n;k++)vis[k]=0;
					s=0;
					dfs2(i,0,j);
					if(s==2)tot++;
				}
			}
			cout<<tot<<'\n';	
		}else{
			for(int i=1;i<=n;i++)cin>>a[i];
			if(a[3]-a[1]>d){
				cout<<"0\n";
				continue;
			}
			int dd=d/(a[2]-a[1]);
			ans=0;
			for(int i=1;i<n-dd-1;i++)ans++;
			cout<<ans<<'\n';
		}
	}
	return 0;
}

