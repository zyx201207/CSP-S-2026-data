#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500009],ans[500009],b[500009];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					for(int l=j;l<k;l++){
						b[l]=-1;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]!=-1){
				ans[a[j]]++;
			}
			else{
				b[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
