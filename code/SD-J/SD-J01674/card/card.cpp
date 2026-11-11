#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],pos[N],ans[M],vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		int cnt=1;
		for(int u=i;u<=n;u=pos[a[u]]+1){
			vis[u]=1;
			ans[a[u]]+=cnt;
			if(!vis[pos[a[u]]+1])cnt++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
