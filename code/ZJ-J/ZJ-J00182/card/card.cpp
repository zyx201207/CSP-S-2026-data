#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],a[500005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int r=1;
	for(int i=1;i<=n;i++){
		if(vis[a[i]]){
			memset(vis,0,sizeof(vis));
		}
		while(!vis[a[r]] and r<=n){
			vis[a[r]]=r;
			r++;
		}
		ans[a[i]]+=r-i;
		vis[a[i]]=i;
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
