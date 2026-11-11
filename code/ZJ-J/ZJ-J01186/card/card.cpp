#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m;
int a[50005];
int ans[50005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int vis[30005];
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				for(int k=vis[a[j]];k<=j;k++){
					vis[a[k]]=0;
				}
				vis[a[j]]=j;
			}else{
				vis[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]!=0){
				ans[j]++;
			}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}