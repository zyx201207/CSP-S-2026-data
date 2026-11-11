#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],x,y;
int w[500005];
int a[505][20005];
int t[505][20005];
int b[500005];
vector <pair<int,int> > ti[500005];
int ans=114514191;
void dfs(int z,int nn,int sum){
	for(int i=1;i<=k[nn];i++){
		if(a[nn][i]==y){
			sum+=w[y]+t[nn][i];
			ans=min(ans,sum);
			return;
		}
		if(a[nn][i]!=z&&b[a[nn][i]]==0){
			b[a[nn][i]]=1;
			for(auto cc:ti[a[nn][i]]){
				int u=cc.first;
				int v=cc.second;
				if(u!=nn){
					dfs(a[nn][i],u,sum+t[nn][i]+t[u][v]);
				}
			}
		}
	}
}
int main(){
	freopen("sudway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ti[a[i][j]].push_back({i,j});
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					dfs(x,i,w[x]+t[i][j]);
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}