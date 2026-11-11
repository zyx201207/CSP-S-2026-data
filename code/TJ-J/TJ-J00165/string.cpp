#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100],b[100],x=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<n;i++){
	    if(b[i]==b[i-1]){
	    	x++;
		}
		else{
			break;
		}
	}
	if(x==n-1){
		cout<<0;
	}
	return 0;
}




















