#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],vis[300005],viss[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool fl=0;
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]=i;
		if(a[i]<a[i-1]){
			fl=1;
		}
	}
	if(!fl){
		for(register int i=1;i<=m;i++){
			ans[i]=vis[i];
			cout<<ans[i]<<" ";
		}
	}else{
		for(register int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			memset(viss,0,sizeof(viss));
			for(register int j=i;j<=n;j++){
				if(vis[a[j]]!=0){
					for(register int k=vis[a[j]];k<=j;k++){
						viss[a[k]]=0;
						vis[a[k]]=0;
					}
					viss[a[j]]=1;
					vis[a[j]]=j;
				}else{
					viss[a[j]]=1;
					vis[a[j]]=j;
				}
			}
			for(register int j=1;j<=m;j++){
				if(viss[j]==1){
					ans[j]++;
				}
			}
		}
		for(register int j=1;j<=m;j++){
			printf("%d ",ans[j]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
