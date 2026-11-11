#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int f=1;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		f=1;
		cout<<"1";
	}
	else{
		f=0;
		cout<<"0";
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f==1){
		f=1;
		cout<<"1";
	}
	else{
		f=0;
		cout<<"0";
	}
	
	int a=s1[2]-'A';
	int b=s2[2]-'A';
	if(s1[2]=='F'){
		a=4;
	}
	if(s2[2]=='F'){
		b=4;
	}
	if((((a>=3&&a<=4)&&(b<=4&&b>=3))||((a>=0&&a<=2)&&(b>=0&&b<=2)))&&a!=b&&f==1){
		f=1;
		cout<<"1";
	}
	else{
		f=0;
		cout<<"0";
	}
	
	if(abs(a-b)==1&&f==1){
		f=1;
		cout<<"1";
	}
	else{
		f=0;
		cout<<"0";
	}
	return 0;
}
