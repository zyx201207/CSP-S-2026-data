#include<bits/stdc++.h> 
using namespace std;
long long a[1000005],n,m,maxx=-1e9;
void dfs(int k,long long sum,bool vis[100005]){
	if(k==m){
		maxx=max(maxx,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(k+1,(sum&a[i]),vis);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		bool vis[100005]={0};
		vis[i]=1;
		dfs(1,a[i],vis);
	}
	cout<<maxx;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
