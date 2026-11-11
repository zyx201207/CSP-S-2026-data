#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],vis[5010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int res[5010];
		for(int j=i;j<=n;j++){
			res[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			for(int k=j-1;k>=i;k--){
				if(res[k]==res[j]){
					for(int t=k;t<=j-1;t++){
						res[t]=-1;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(res[j])vis[res[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<' ';
	}
	return 0;
}
