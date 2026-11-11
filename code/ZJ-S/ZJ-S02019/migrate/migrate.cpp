#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int a[305];
int g[305][305];
int dfs(int u,int v,int U,int V,int p=0){
	if(u==v&&p==g[U][V]) return 1;
	int sum=0;
	for(int k=u+1;k<=v&&abs(a[k]-a[u])<=d;k++){
		sum+=dfs(k,v,U,V,p+1);
	}
	return sum;
}
void unmain(){
	cin>>n>>d;
	memset(g,0x1f,sizeof g);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[i][i]=0;
	}
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]<=d) g[i][i+1]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[k])<=d&&abs(a[j]-a[k])<=d){
					g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
				}
			}
		}
	}
//	cout<<dfs(1,4,1,4)<<"*&#($&($#\n";
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dfs(i,j,i,j)==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
	unmain();
	}
	return 0;
}
