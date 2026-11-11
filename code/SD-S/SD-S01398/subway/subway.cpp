#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,a[510],g[510][510],vis[510],mt=0x3f3f3f3f,ttt=0,flag=1;
void dfs(int u,int end,ll time){
	if(u==end){
		mt=min(mt,time);
		return ;
	}
	for(int i=1;i<=m;i++){
		if(g[u][i]<=0x3f3f3f3f&&vis[i]==0){
			vis[i]=1;
			dfs(i,end,time+g[u][i]);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		ll b[k],e[k];
		for(int j=1;j<=k;j++){
			cin>>b[j]>>e[j];
			if(ttt==0) ttt=e[j];
			else if(ttt!=0&&ttt!=e[j]) flag=0;
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				g[b[j]][b[l]]=min(g[b[j]][b[l]],e[j]+e[l]);
			}
		}
	}
	if(!flag){
		for(int i=1;i<=m;i++) g[i][i]=0x3f3f3f3f3f3f3f3f;
		while(q--){
			memset(vis,0,sizeof vis);
			int start,end;
			mt=0x3f3f3f3f;
			cin>>start>>end;
			vis[start]=1;
			dfs(start,end,0);
			cout<<mt+a[start]+a[end]<<'\n';
		}
	}else{
		for(int i=1;i<=m;i++) g[i][i]=0x3f3f3f3f3f3f3f3f;
		while(q--){
			queue<pair<int,int>>qu;//!?ÇøÇø?! 
			memset(vis,0,sizeof vis);
			ll start,end,ans=0;
			cin>>start>>end;
			qu.push({start,1});
			while(!qu.empty()){
				int u=qu.front().first,t=qu.front().second;
				if(u==end){
					ans=t;
					break;
				}
				qu.pop();
				for(int i=1;i<=m;i++){
					if(g[u][i]<0x3f3f3f3f&&vis[i]==0){
						vis[i]=1;
						qu.push({i,t+1});
					}
				}
			}
			cout<<ans*ttt+a[end]+a[start]<<'\n';
		}
	}
	return 0;
}
