#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1[4],s1[4],c2[4],s2[4];
	cin>>c1[4]>>s1[4]>>c2[4]>>s2[4];
	if(c1==c2&&s1+1==s2){
		cout<<"1111";
	}
	else if(c1==c2&&s1+2==s2){
		cout<<"1110";
	}
	else if(c1==c2&&s1+3==s2){
		cout<<"1110";
	}
	else if(c1==c2&&s1+4==s2){
		cout<<"1100";
	}
	else if(c1==c2&&s1+5==s2){
		cout<<"1100";
	}
	else if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<"1000";
	}
	return 0;
} 
