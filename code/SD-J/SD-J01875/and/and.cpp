#include<bits/stdc++.h>
using namespace std;
int n,m;
int const A=2e5+1;
int arr[A],vis[A];
int Max=0;
void dfs(int num,int stp){
	if(stp==m){
		Max=max(Max,num);
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		int x=num&arr[i];
		dfs(x,stp+1);
		vis[i]=0;
	}
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=n;++i){
		vis[i]=1;
		dfs(arr[i],1);
		vis[i]=0;
	}
	printf("%d",Max);
	return 0;
}
