#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(a[x]<a[y]){
				int t=a[x];
				a[x]=a[y];
				a[y]=t;
			}
		}
	}
	cout<<a[n-m];
}
