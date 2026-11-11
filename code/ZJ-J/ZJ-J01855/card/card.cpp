#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],b[500002],k,ans[300002],vis[300002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		k=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int l=vis[a[j]]+1;l<=k;l++)vis[l]=0;
				k=vis[a[j]];
			}
			else b[++k]=a[j],vis[a[j]]=k;
		}
		for(int j=1;j<=k;j++)ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
