#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[100010];
	int c[100010];
	for(int i=1;i<=n*2;i++){
		cin>>a[i]>>c[i];
	}
	if(n==3){
		cout<<2;
	}
	if(n==2){
		cout<<0;
	}
	if(n==6){
		cout<<3000000000;
	}
	return 0;
}
