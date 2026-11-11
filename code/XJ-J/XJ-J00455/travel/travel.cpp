#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string num1=s1.substr(0,2);
	string num2=s2.substr(0,2);
	char a=s1[2];
	char b=s2[2];
	if(c1==c2){
		if(num1==num2){
			if((a<='C'&&b<='C')||(a<='F'&&b<='F')){
				if(char(a+1)==b||char(b+1)==a||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
					cout<<"1111";
				}else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else{
		cout<<"0000";
	}
	return 0;
}