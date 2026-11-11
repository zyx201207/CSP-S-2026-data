#include<bits/stdc++.h>
using namespace std;
const int inf=505;
struct node{
	int t,a;
}mp[inf][inf];
int c,n,m,d,q;
int w[inf];
int k[inf];
int x[inf],y[inf];
int vis[inf][inf];
int ans=0x3f3f3f3f;
void dfs(int x,int y,int z,int step){
	if(mp[x][y].a==z){
		ans=min(ans,step);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(mp[i][j].a==mp[x][y].a&&vis[i][j]==0){
				vis[i][j]=1;
				dfs(i,j,z,step+mp[i][j].t);
				vis[i][j]=0;
			}else if(vis[x][j]==0){
				vis[x][j]=1;
				dfs(x,j,z,step+mp[x][j].t);
				vis[x][j]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>mp[i][j].a>>mp[i][j].t;
		}
	}
	while(q--){
		int x,y;
		int ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(mp[i][j].a==x){
					vis[i][j]=1;
					dfs(i,j,y,0);
					vis[i][j]=0;
				}
			}
		}
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<endl;
	}
	return 0;
}