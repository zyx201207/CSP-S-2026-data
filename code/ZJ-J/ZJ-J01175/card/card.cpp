#include<bits/stdc++.h>
using namespace std;
long long n,m,x=2,mx=0;
int js[3001],ans[3005],a[5005],vis[5001],cnt=0,f=0,cct=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		memset(vis,0,sizeof(vis));
		memset(js,0,sizeof(js));
		for(int j=i;j<=n;j++){
			if(js[a[j]]!=0&&vis[js[a[j]]]==0){
				for(int k=j-1;k>=js[a[j]];k--){
					vis[k]=1;
				}
			}
			js[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==0){
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
