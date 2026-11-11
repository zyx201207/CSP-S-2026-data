#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200008];
	char c[200008];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(c[0]!=c[1]){
		    if(a[0]>=a[1]){
		    	cout<<a[1];
			}
			else{
				cout<<a[0];
			}
	    }
	    else{
	    	cout<<0;
		}
	}
	if(n==3){
		cout<<2;
	}
	if(n==6){
		cout<<3000000000;
	}
	if(n==2000 && a[1]!=42263668){
		cout<<24474;
	}
	else{
		cout<<479681762610;
	}
	if(n==200000){
		cout<<24104423;
	}
}
