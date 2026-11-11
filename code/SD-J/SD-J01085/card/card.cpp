#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[300005],cnt,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis)); 
		cnt=1;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=j;
			}else{
				cnt=j;
				vis[a[j]]=j;
			}
		}
		for(int k=1;k<=m;k++){
			if(vis[k]>=cnt){
				ans[k]++;
			}
		} 	
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
