#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int n,m,x=0,c=0,b=0,d=0,j=0;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]){
			b=a[i];}
		if(a[i]<a[i-1]){
			c=a[i];
		}
	}
	d=(b+c)/2;
	 for(int i=0;i<n;i++){	
		if(a[i]<=d){
			x++ ;
			j=d-a[i]+j;
		} 
	 	}
	 	if(j=m){
		cout<<x;}
	return 0;
}
