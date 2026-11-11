#include<bits/stdc++.h>
using namespace std;
int c,n,q,d,m,ans;
int w[500005];
int a[20][500005];
bool vis[500005];
void dfs(int x,int y,int sum){
	if(x==y){
		ans=min(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i][x]!=0){
			for(int j=1;j<=m;j++){
				if(a[i][j]!=0&&vis[j]!=0){
					vis[j]=1;
					dfs(j,y,sum+a[i][x]+a[i][j]);
					vis[j]=0;
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		for(int j=1;j<=n;j++){
			int u,v;
			cin>>u>>v;
			a[i][u]=v;
		}
	}
	if(c<=3){
		while(q--){
			ans=100000000;
			int u,v;
			cin>>u>>v;
			dfs(u,v,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
