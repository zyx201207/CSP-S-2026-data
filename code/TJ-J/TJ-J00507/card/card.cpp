#include<bits/stdc++.h>
using namespace std;
int n,m;
int crd[500003];
int ds[300003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>crd[i];
	}
	for(int i=1;i<=n;i++){
		int zm[500005]={};
		for(int j=i;j<=n;j++){
			zm[j]=crd[j];
			for(int k=j-1;k>=i;k--){
				if(zm[k]==zm[j]){
					for(int l=j-1;l>=k;l--) zm[l]=0;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			ds[zm[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ds[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
