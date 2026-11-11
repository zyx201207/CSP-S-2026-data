#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num=0,maxa=0;
	cin>>n>>m;
	int a[200011];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+0,a+n);
		cout<<a[n-1];
		return 0;
	}
	else{
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				num=a[j] & a[k];
				maxa=max(maxa,num);
			}
		}
	}
	cout<<maxa;
	return 0;
}
