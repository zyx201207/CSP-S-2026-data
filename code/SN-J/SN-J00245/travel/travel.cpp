#include<bits/stdc++.h>
using namespace std;

string x1,x2,x3,x4;

void f(){
	if(x1==x3)cout<<1;
	else{
		cout<<"0000"<<endl;
		return;
	}
	if(x2[0]==x4[0]&&x2[1]==x4[1]){
		cout<<1;
		if(x2[2]<='C'&&x4[2]<='C'||x2[2]>='D'&&x4[2]>='D'){
			cout<<1;
			if(abs((int)x2[2]-(int)x4[2])==1)cout<<1;
			else cout<<"0";
		}
		else cout<<"00";
	}
	else cout<<"000";
	
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2>>x3>>x4;
	f();	
	return 0;
}
