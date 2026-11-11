#include<bits/stdc++.h>
using namespace std;
int n,m,ra,rb;
int a[200010],ans[200010],vis[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans[1]<(a[i]&a[j])){
				ra=i;
				rb=j;
			}
			ans[1]=max(ans[1],a[i]&a[j]);
		}
	}
	vis[ra]=1;
	vis[rb]=1;
	for(int k=2;k<m;k++){
		for(int j=1;j<=n;j++){
			if(vis[j]==1)continue;
			if(ans[k]<ans[k-1]&a[j]){
				rb=j;
			}
			ans[k]=max(ans[k],ans[k-1]&a[j]);
		}
		vis[rb]=1;
	}
	cout<<ans[m-1];
	return 0;
}

