#include<bits/stdc++.h>
using namespace std;
long long a[200005]={};
int n,m;
bool vis[200005]={};
long long ans=-1;
void dfs(int i,long long ann,int k){
	if(i>=m){
		ans=max(ans,ann);
		return;
	}
	for(int j=k;j<=n;j++){
		if(!vis[j]){
			vis[j]=1;
			dfs(i+1,ann&a[j],j);
			vis[j]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i],i);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
