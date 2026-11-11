//郝苑博 延安市新区第一中学 SN-J00851 
#include<bits/stdc++.h>
using namespace std;

int main(){
 	long long n,m,a[200005],maxa=0;
 	cin>>n>>m;
 	for(int i=0;i<n;i++){
 		cin>>a[i]; 
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(a[i+j]&a[i+j+1]>maxa) {
				maxa=a[i+j]&a[i+j+1];
			}
		}
	}
	cout<<maxa;
	return 0;
}
