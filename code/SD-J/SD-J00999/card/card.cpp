#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010],con[500010],sit[500010],vis[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(sit[a[i]]==0){
			sit[a[i]]=i;
		}else{
			con[i]=sit[a[i]];
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(con[i]!=0){
				if(vis[a[i]]!=j){
					vis[a[i]]=j;
					ans[a[i]]++;
				}
				i=con[i]-1;
			}else{
				if(vis[a[i]]!=j){
					vis[a[i]]=j;
					ans[a[i]]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
