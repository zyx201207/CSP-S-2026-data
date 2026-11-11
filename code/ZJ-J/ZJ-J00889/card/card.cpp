#include<bits/stdc++.h>
using namespace std;
int a[500007],ans[300007],st[500007],vis[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		int len=0;
		for(int j=i;j<=n;j++){
			st[++len]=a[j];
			if(vis[a[j]]==1){
				while(--len){
					if(a[j]==st[len]) break;
					vis[st[len]]=0;
				}
			}
			vis[a[j]]=1;
		}
		for(int j=1;j<=len;j++) ans[st[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}