#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 	
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	int sum=a[n-1];
//	cout<<sum<<endl;
//	for(int i=n-1;i>=0;i--){
//		cout<<i<<": "<<a[i]<<endl;
//	}
	if(m==n){
		for(int i=n-2;i>=0;i--){
			sum=sum^a[i];
		} 
		cout<<sum<<endl;
		return 0;
	}
	for(int i=n-2;i>=0;i--){
		sum=sum^a[i]; 
	}
	cout<<sum<<endl;
	return 0;
} 
