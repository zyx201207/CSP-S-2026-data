#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum,x,y;
	cin>>n;
	long long a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=0;i<n/2;i++){
		if(b[0+i]!=b[n-1-i]){
		    sum+=min(a[0+i],a[n-1-i]);
		}
	}
	cout<<sum-1;
	return 0;
} 
