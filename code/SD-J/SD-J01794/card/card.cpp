#include<bits/stdc++.h>
using namespace std;
int i,m,l,j,n,fz[500000],a[500000]={0},t[300000]={0};
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(l=i;l<=n;l++){
			for(j=1;j<=l+1;j++){
				if(fz[j]==a[l]){
					continue;
				}
			}
			fz[j]=a[l];
			for(j+=1;j<=n;j++){
				fz[j]=0;
			}
		}
		for(l=i;l<=n;l++){
			t[fz[l]]++;
		}
		for(l=i;l<=n;l++){
			fz[l]=0;
		}
	}
	t[a[n]]=n;
	for(i=1;i<=m;i++){
		while(t[i]>n){
			t[i]-=n;
		}
		cout<<t[i]<<" ";
	}
	return 0;
}
