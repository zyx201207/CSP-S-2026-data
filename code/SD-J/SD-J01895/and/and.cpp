#include<bits/stdc++.h>
using namespace std;
int const A=1e5+1; 
int n,m,arr[A],Max=0,vis[A];
void dfs(int a,int b,int sum){
	if(b==0){
		Max=max(Max,sum);
	}
	vis[a]=1;
	for(int i=1;i<=n;++i){
		if(vis[i]=0){
			vis[i]=1;
			dfs(i,b-1,sum&arr[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=n;++i){
		dfs(i,m,arr[i]);		
	
	}

	printf("%d\n",Max);
	return 0;
}	
