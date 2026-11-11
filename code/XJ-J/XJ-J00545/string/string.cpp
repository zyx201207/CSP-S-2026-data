#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n],c[n];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(c[0]==c[1]){
		cout<<"0";
	}else{
		cout<<"2";
	}
	return 0;
}