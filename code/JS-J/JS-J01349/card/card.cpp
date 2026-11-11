#include<bits/stdc++.h>
using namespace std;
int a[500001],c[500001],b[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n-1;j>=i;j--){
			for(int k=j+1;k<=n;k++){
				if(c[j]==c[k]){
					for(int l=j;l<k;l++){
						c[l]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(c[j]!=0){
				b[c[j]]++;
			}
		}
		for(int j=i;j<=n;j++){
			c[j]=a[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
