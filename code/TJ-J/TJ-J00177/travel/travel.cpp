#include<bits/stdc++.h>
using namespace std;
int main(){
	char c1,s1,c2,s2;
	char x,y;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
	}y=s1/100;x=s2/100;
	if(x==y){
		cout<<"1";
	}else{
		cout<<"000";
	}y=s1%100;x=s2%100;
	if(y<=67&&x<=67){
		cout<<"1";
		if(s1+1==s2||s2+1==s1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(x>67&&y>67){
		cout<<"11";
	}else{
		cout<<"0";
	}
	return 0;
}  
