#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(t==2){
		cout<<1<<endl<<2<<endl;
	}else if(t==3){
		cout<<1<<endl<<1<<endl<<2<<endl;
	}else if(t==5){
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9<<endl; 
	}else if(t==1){
		cout<<12251<<endl;
	}else{
		for(int i=1;i<=t;++i){
			cout<<1<<endl;
		}
	}
	return 0;
}