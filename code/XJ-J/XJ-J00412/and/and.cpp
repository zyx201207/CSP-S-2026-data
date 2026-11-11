#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and2.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,x;cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b=0;
	for(int i=0;i<n-x;i++){
		int j=a[i];
		for(int j=1;j<x;j++){
			j=j&a[i+j];
		}
		if(j>b){
			b=j;
		}
	}
	cout<<b;
	return 0;
}
