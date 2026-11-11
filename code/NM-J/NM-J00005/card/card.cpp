#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,js,a[]={},b[]={},c[]={};
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
		for(int j=i;j>0;j--){
			if(b[i]=b[j]){
				for(int s=j;s<i-1;s++){
					b[s]=0;
				}
				swap(b[i],b[i-j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(i-1==b[j]){
				c[i-1]++;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(c[i]!=0){
			cout<<c[i];
		}
		js++;
		if(js>n){
			cout<<"cuowu";
		}
	}
	return 0;
}
