#include <bits/stdc++.h>
using namespace std;
int main(){
	string c1,c2,s1,s2;
	int a=1;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<'1';
	}else{
		cout<<'0';
		a=0;
	}if((c2[0]==s2[0]&&c2[1]==s2[1])&&a){
		cout<<'1';
	}else{
		cout<<'0';
		a=0;
	}if(((c2[2]<='C'&&s2[2]<='C')||(c2[2]>='D'&&s2[2]>='D'))&&a){
		cout<<'1';
	}else{
		cout<<'0';
		a=0;
	}if((c2[2]-s2[2]==1||c2[2]-s2[2]==-1)&&a){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
