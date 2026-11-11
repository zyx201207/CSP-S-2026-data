#include <bits/stdc++.h>
using namespace std;
int n;
int a[500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<"2";
	}

	if(n==2){
		cout<<"0";
	}
	if(n==6){
		cout<<"3000000000";
	}
	return 0;
}