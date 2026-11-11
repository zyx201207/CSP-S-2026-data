#include<bits/stdc++.h>
using namespace std;
int a[500005]={},sum[300005]={},b[500005]={};
int main(){
	long long n,m,s=0,l=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			b[j]=a[j];
			for(int l=i;l<j;l++){
				if(b[j]==b[l]){
					for(int t=l;t<j;t++){
						b[t]=0;
					}
					break;
				}
			}
		}
		for(int j=i;j<n;j++){
			sum[b[j-1]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<sum[i];
		if(i<m){
			cout<<' ';
		}
	}
	return 0;
}
