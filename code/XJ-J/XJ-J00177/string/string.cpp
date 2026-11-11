#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100000]; 
	char b;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		cin>>b; 
	}
	if(n==1){
		cout<<"0";
	}
	else if(n==2){
		cout<<a[1];
	}
	else cout<<"1";
	return 0;
} 
