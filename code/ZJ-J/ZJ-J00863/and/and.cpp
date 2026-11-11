#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005],k=INT_MAX,ans,anss;
void dfs(int dep,int sum){
	if(dep>m){
		ans=max(ans,sum);
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				dfs(dep+1,sum&a[i]);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	anss=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		anss=min(anss,a[i]);
	}
	if(n>2000){
		cout<<anss;
		return 0;
	}
	dfs(1,k);
	cout<<ans;
	return 0;
}
