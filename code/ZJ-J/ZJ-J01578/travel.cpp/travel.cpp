#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
				if(abs(s1[2]-s2[2])==1){
					cout<<"1111";
					return 0;
				}
				cout<<"1110";
			}
			cout<<"1100";
		}
	}
	return 0;	
}
