#include<bits/stdc++.h>
using namespace std;
int a[500001],c[500001];
int b[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	while(n--){
	    a[i]=c[i];
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(a[j]==a[k]&&a[j]>0){
					for(int l=j;l<k;l++){
						a[l]=0;
					}
				}
			}
			for(int z=1;z<=m;z++){
				if(a[j]==z)b[z]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
