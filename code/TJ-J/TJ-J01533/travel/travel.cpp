#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,a,b;
	cin>>x>>y>>a>>b;
	if(x==a){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(y[0]==b[0]&&y[1]==b[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((y[2]=='C'&&b[2]=='D')||(y[2]=='D'&&b[2]=='C')){
		cout<<"00";
		return 0;
	}else{
		cout<<1;
	}
	if(abs(b[2]-y[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
