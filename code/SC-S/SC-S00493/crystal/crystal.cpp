#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,sum=0;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int ans=0,num=1;
	while(num<a[n-1]+m){
		num*=2;
		ans++;
	}
	cout<<ans;
	return 0;
} 