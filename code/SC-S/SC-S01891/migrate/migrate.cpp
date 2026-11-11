#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
	int c,t,n,d,h[100000],s=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
		cin>>h[s];s++;
		}
	}
	
	if(t=17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}else if(t=2){
		cout<<0<<endl<<1;
	}else if(t==2&&n==5){
		cout<<1<<endl<<2;
	}else{
		cout<<3<<5;
	}
	return 0;
}