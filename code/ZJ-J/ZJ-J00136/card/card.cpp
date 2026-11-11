#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int vis[300005];
int ans[500005];
bool c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=j;
			}else{
				for(int k=vis[a[j]];k<j;k++){
					vis[a[k]]=0;
					c[k]=1;
				}
				vis[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(!c[j]){
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}