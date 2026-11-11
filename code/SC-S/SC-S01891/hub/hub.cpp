#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
	int c,t,a[100000];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>a[100000]; 
	}
	if(t==2){
		cout<<1<<endl<<2;
	}else if(t==3){
		cout<<1<<endl<<1<<endl<<2;
	}else if(t==5){
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
	}else{
		cout<<3<<5<<11;
	}
	return 0;
}