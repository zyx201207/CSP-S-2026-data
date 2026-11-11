#include<bits/stdc++.h>
using namespace std;
int c,n,m,v[500005],k[501],a[501][500005],q,d,r[10005][2],t[501][500005],ans,vis[500005];
void dfs(int x,int n,int ti){
	if(x==n){
		ti+=v[n];
		ans=max(ti,ans);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(vis[a[i][j]]==1){
				vis[a[i][j]]=1;
				dfs(a[i][j],n,ti+t[i][x]);
				vis[a[i][j]]=0;
			}
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>v[i];
	for(int i=1;i<=n;i++){ 
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		cin>>r[i][0]>>r[i][1];
		dfs(r[i][0],r[i][1],v[r[i][0]]);
	}
}

