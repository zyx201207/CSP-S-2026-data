#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans,w[5005],ji[5005][5005],t2[5005][5005],y,vis[5005][5005],k[2005];//路到地铁站 
long long a[5005][5005],t[5005][5005];
void dfs(int x,int u,long long h,bool k2){//1站厅 0站台路 
	if(u==y){
		ans=min(ans,h);
		return ;
	}
	if(h>=ans)return ;
	//站厅到站台
	if(k2==1){
		for(int i=1;i<=n;i++){//去了第i条路 
			if(t2[i][x]!=0&&vis[i][x]==0){
				vis[i][x]=1;
				vis[x][i]=1;
				dfs(x,i,h+t2[i][x],0);
				vis[i][x]=0;
				vis[x][i]=0;
			}
		}
	}
	else {
		for(int i=1;i<=m;i++){
			if(t2[u][i]!=0&&vis[u][i]==0){
				vis[u][i]=1;
				vis[i][u]=1;
				dfs(i,0,h+t2[u][i],1);
				vis[u][i]=0;
				vis[i][u]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			t2[i][a[i][j]]=t[i][j];//
		}
	}
	
	
/*
	0 2 5 20 2
	4 1 9 2 5 
	3 1 5 2 7 4 6 
	3 2 3 3 4 5 7 
	1 3 
	1 2
*/
 
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		dfs(x,0,0,1);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0; 
}
