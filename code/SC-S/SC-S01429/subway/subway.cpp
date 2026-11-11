#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int mx=1e5+10;
ll c,n,m,d,q;
ll w[5*mx],k[5*mx],a[510][mx],t[510][mx],vis[5*mx][50];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][a[i][j]],vis[i][a[i][j]]==1;
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			if(vis[i][x]==vis[i][y]==1) cout<<t[i][x]+t[i][y]+w[x]+w[y];
		}
			
	return 0;
} 