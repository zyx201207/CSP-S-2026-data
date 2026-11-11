#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a[200000]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				cout<<a[i];
				break;
			}
		}
	}
	
	
	
	return 0;
}
