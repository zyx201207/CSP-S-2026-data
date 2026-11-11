#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[100000],t[100000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(m=2){
		for(int i=0;i<n;i++){
		ans=max(ans,a[i]&a[i+1]);
	}
	}
	else{
		for(int i=0;i<n;i++){
			ans=max(ans,(a[i]&a[m-1])&a[m-2]);
		}
	} 
	
	cout<<ans;
}
