#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char z[n+5];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>z[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(z[0]!=z[1]){
			if(a[0]>a[1])cout<<a[1];
			else if(a[0]<a[1])cout<<a[0];
			else cout<<a[0];}
		else{
			cout<<0;
		}
	}
	return 0;
}
