#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool key=false;
int main(){
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	if(s1.substr(0,2)==s2.substr(0,2))cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	
	int da=s1[2]-'A',db=s2[2]-'A';
	if(da<3&&db<3||da>=3&&db>=3)cout<<1;
	else cout<<0;
	
	if(abs(da-db)==1&&!(da==2&&db==3||da==3&&db==2))cout<<1;
	else cout<<0;
	
	return 0;
}
