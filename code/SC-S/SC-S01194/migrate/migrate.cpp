#include<bits/stdc++.h>
using namespace std;
int main(){	
	int m,n,k;
	freopen("crystal.in","m",stdin);
	freopen("crystal.out","k",stdout);			
	cin>>m>>n;
	int a[m];	
	int c[m]={};	
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(a[i]>a[j]){
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	for(int i=0;i<m;i++){
		k=n;
		for(int j=i;j>=0;j--){			
			k=a[j]+k;
			if(k>=(i-j+1)*a[i]){
				c[i]++;	
			}
			else break;
		}
	}
	k=0;
	for(int i=0;i<m;i++){
		if(c[i]>k){
			k=c[i];
		}
	}
	return 0;
}