#include<bits/stdc++.h>
using namespace std;
long long a[200005],vis[200005],n,m;
long long he;
long long ans;
long long c[200005];
void dfs(int y){
	if(y==m){
		he=c[0];
		for(int i=1;i<m;i++){
			he=he&c[i];
		}
		ans=max(ans,he);
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			c[y]=a[i];
			vis[i]=1;
			dfs(y+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
