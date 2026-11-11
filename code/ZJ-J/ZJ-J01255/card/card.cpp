#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[300005];
int ans[300005];
int a[500005];
int b[500005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i,x=i;j<=n;j++){
			if(vis[a[j]]==1){
				for(int k=j-1;b[k+1]!=a[j]&&k>=i;k--){
					vis[b[k]]=0;
					b[k]=0;
				}
			}
			vis[a[j]]=1;
			b[j]=a[j];
		}
		for(int j=1;j<=n;j++){
			ans[b[j]]++;
			vis[b[j]]=0;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
