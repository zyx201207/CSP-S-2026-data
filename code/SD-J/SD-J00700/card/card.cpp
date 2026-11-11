#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],dis[500005],mp[300005],ans[300005];
bool vis[500005];
void dfs(int x,int d){
	if(x==n) ans[a[n]]+=d;
	else if(vis[x]){
		ans[a[x]]+=d;
		dfs(x+1,d);
	}else{
		dfs(mp[a[x]],d);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		if(!mp[a[i]]){
			mp[a[i]]=i;
			vis[i]=true;
		}
		dis[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			dfs(i,dis[a[i]]);
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}

//11:04
//I may be AK CSP-J.
//rp+=INF;
//
//补豪孩子们我要被CSP-S狠狠肘击了 
//What can I say? Manba out.

