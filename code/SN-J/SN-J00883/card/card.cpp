#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,b[11]={};
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c[n];
	for(int i=0;i<n;i++){
		c[i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(c[i]==c[j]){
				for(int z=0;z<c[j];z++){
					c[z]=0;
				}
			}else{
				b[j]=c[j];
			}
		}
	}
	for(int i=0;i<10;i++){
		if(b[i]>0){
			cout<<b[i]<<" ";
		}
	}
	return 0;
}
