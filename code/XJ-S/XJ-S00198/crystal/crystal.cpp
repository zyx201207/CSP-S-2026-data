#include<bits/stdc++.h>
using namespace std;
int a[100086];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]+a[1]==a[2]){
		cout<<3;
	} 
	if(a[0]+a[1]+m==a[2]*2){
		cout<<3;
	} 
	if(a[0]+a[1]==a[2]+a[3]){
		cout<<4;
	} 
	return 0;
} 
