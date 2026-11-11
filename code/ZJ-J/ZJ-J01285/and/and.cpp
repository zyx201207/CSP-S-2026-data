#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a[1000];
	long long ans=0;
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		ans=max(a[i],a[i]&a[i+i]);	
	}
	cout<<ans;
	return 0;
}
