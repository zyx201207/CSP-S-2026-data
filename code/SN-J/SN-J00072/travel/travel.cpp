#include<iostream>
using namespace std;

int main(){
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1=='01A' && s2=='01B') cout<<"111";
	}else{
		cout<<"0000";
	}
	
	return 0;
}

