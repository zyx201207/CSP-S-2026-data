#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[1000];
	char b[1000],c[1000000];
	long long n,m=0,l=0,l1=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		l1=l1+a[i];
		cin>>b[i];
		for(int j=0;j<a[i];j++){
			c[l]=b[i];
			l++;
		}
	}
	for(int i=0;i<l1/2;i++){
		if(c[i]!=c[l1-i-1]){
			m++;
		}
	}
	cout<<m;
	return 0;
} 
