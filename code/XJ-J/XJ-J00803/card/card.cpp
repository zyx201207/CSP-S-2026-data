#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int r[m]={0};
	for(int i=0;i<n;i++){
		for(int l=0;l<n;l++){
			b[l]=a[l];
		}
		for(int l=0;l<n;l++){
			for(int j=0;j<i;j++){
				b[j]=0;
			}
			for(int j=l;j<n;j++){
				if(b[l]==b[j]){
					for(int k=l;k<j;k++){
						b[k]=0;
					}
				}
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(b[j]==i+1){
					r[i]++;
				}
			}
		}
	}
	for(int l=0;l<m;l++){
		cout<<r[l]<<" ";
	}
	return 0;
}