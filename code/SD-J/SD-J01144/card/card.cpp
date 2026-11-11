#include<bits/stdc++.h>
using namespace std;
int ans[300005],a[500005],n,m,b[500005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		int cb=0;
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				++cb;
				b[cb]=a[j];
				vis[a[j]]=cb;
			}else{
				cb=vis[a[j]];
			}
		}
		for(int j=1;j<=cb;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
} 
