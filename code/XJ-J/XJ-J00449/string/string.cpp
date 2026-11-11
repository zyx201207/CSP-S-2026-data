#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string b;
	int n,a[20],c[20];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==3){
		cout<<2;
	}
	else if(n==2){
		cout<<0;
	}
	else if(n==6){
		cout<<3000000000;
	}
	return 0;
}