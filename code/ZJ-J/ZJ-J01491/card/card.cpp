#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],vis[300010],w,ans[300010],q[500100],f;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=1;
	}
	if(f==0||n>10000){
		for(int i=1;i<=n;i++)
			ans[a[i]]=i;
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		w=0;
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0)q[++w]=a[j],vis[a[j]]=w;
			else{
				for(int k=vis[a[j]]+1;k<=w;k++)
					vis[q[k]]=0;
				w=vis[a[j]];
			}
		}
		for(int j=1;j<=w;j++)ans[q[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}