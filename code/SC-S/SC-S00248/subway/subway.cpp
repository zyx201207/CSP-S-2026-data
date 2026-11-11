#include<bits/stdc++.h>
using namespace std;int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int ct[1002][1002],t[502][1003],ans=-1;bool b[1002]={0};
void dfs(int now,int end,int cost,int lastlu){
	if(now==end){
		cost+=t[lastlu][end];
		if(ans==-1)ans=cost;
		else ans=min(ans,cost);
		return;
	}
	for(int i=1;i<=m;i++){
		if(ct[now][i]&&!b[i]){
			b[i]=1;
			if(!lastlu)dfs(i,end,cost+t[ct[now][i]][now],ct[now][i]);
			else if(ct[now][i]==lastlu)dfs(i,end,cost,ct[now][i]);
			else dfs(i,end,cost+t[lastlu][now]+t[ct[now][i]][now],ct[now][i]);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;vector<int>w(m+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c>=7&&c<=11){
		int k,u,v;ans=-1;
		for(int i=1;i<=n;i++){
			cin>>k;
			if(k==2){
				cin>>u;cin>>t[i][u];cin>>v;cin>>t[i][v];
				ct[u][v]=ct[v][u]=i;
			}else{
				cin>>u;cin>>t[i][u];
			}
		}//ok
		while(q--&&cin>>u>>v){
			ans=-1;
			for(int i=0;i<=m;i++)b[i]=0;
			b[u]=1;dfs(u,v,0,0);
			cout<<w[u]+w[v]+ans<<"\n";
		}
	}else{
		int k,u,v,a,b;ans=-1;
		cin>>k>>u>>v;
		while(q--&&cin>>a>>b){
			cout<<w[a]+w[b]+2*v<<"\n";
		}
	}
	return 0;
}
/*
7 2 2 20 3
5 1 2
2 1 2 3 1
2 2 4 3 2
2 3
1 3 
1 2*/