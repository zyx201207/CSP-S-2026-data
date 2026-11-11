#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],vis[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0)
				vis[a[j]]=j;
			else{
				int nw=vis[a[j]];
				for(int k=1;k<=m;k++){
					if(vis[k]>nw)
						vis[k]=0;
				}
				vis[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
			if(vis[j])
				ans[j]++;
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
