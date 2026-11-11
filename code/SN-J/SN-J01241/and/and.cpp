#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	int n,m,ans;
	cin>>n>>m;	
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	ans=a[n]&a[n-1];
	for(int i=n-2;i>n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	freopen("and.out","w",stdout);
	
} 
