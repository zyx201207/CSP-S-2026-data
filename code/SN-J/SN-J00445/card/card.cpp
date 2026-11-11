#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,c[500005],ci,ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i-1;j<n;j++){
			for(int k=0;k<ci;k++){
				if(a[j]==c[k]){
					ci=k;
					for(int l=k;l<ci;l++){
						c[l]=0;
					}
				}
			}c[ci++]=a[j];
		}for(int j=0;j<ci;j++){
			ans[c[j]]++;
			c[j]=0;
		}ci=0;
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
