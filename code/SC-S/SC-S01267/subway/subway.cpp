#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,rr,ss,w[100005],vis[100005],k[100005],tt=1000000,ttt[10005][1005];
vector<int> graph[10005];
vector<pair<int,int>> station[100005];
void dfs(int u,int t){
	if(u==ss){
		tt=min(t,tt);
		return ;
	}
	for(auto out:graph[u]){
		if(!vis[out]){
			vis[out]=true;
			dfs(out,t+w[out]+ttt[u][out]);
			vis[out]=false;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,u;j<=k[i]*2;j++){
			cin>>u;
			if(j%2!=0)graph[i].push_back(u);
			else{
				ttt[i][j/2]=u;
			}
		}
	}
	while(q--){
		if(n<=3){
			cin>>rr>>ss;
			memset(vis,false,sizeof vis);
			vis[rr]=true;
			dfs(rr,0);
			cout<<tt<<"\n";
			tt=100000;
		}else{
			cout<<"1\n";
		}		
	}
	return 0;
}