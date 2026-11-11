#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[500005],cnt,ans[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,sizeof(vis),0);
		memset(b,sizeof(b),0);
		cnt=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=++cnt;
				b[cnt]=a[j];
			}
			else{
				for(int k=vis[a[j]]+1;k<=cnt;k++){
					vis[b[k]]=0;
				}
				cnt=vis[a[j]];
			}
//			cout<<cnt<<'\n';
		}
		for(int j=1;j<=cnt;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
