#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	int n,m,temp,ans=3;
	cin>>n>>m;
	int a[10000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>a[i+1]){
		temp=a[i];
		a[i]=a[i+1];
		a[i+1]=temp;
		}	
	}
	for(int i=0;i<n;i++){
		if(a){
			ans++;
		}
		
	}
	cout<<ans;
	
	return 0;
} 
