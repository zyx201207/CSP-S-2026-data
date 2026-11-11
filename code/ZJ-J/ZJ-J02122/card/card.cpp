#include<bits/stdc++.h>
using namespace std;
int n,m,vis[300010],a[500010],cnt,ans[300010],maxx,c[500010],flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<maxx) flag=1;
		maxx=max(a[i],maxx);
		if(a[i]!=a[i-1]){
			c[cnt]=i;
			cnt++;
		}
	}
	c[m]=n+1;
	if(flag==0){
		for(int i=1;i<=m;i++){
			cout<<c[i]-1<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				for(int k=vis[a[j]];k<j;k++){
					vis[a[k]]=0;
				}
			}
			vis[a[j]]=j;
		}
		for(int i=1;i<=m;i++){
			if(vis[i]!=0){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
