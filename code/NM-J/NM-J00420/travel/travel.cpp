#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1=0;
	char s1[105]={};
	int c2=0;
	char s2[105]={};
	char n='0';
	char m='0';
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]<='C'&&s2[2]<='C'){
		cout<<"1";
		n=max(s1[2],s2[2]);
		m=min(s1[2],s2[2]);
		if(n-m==1){
			cout<<"1";
			n='0';
			m='0';
		}else{
			cout<<"0";
		}
	}else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]>='D'&&s2[2]>='D'){
		cout<<"1";
		
			cout<<"1";
		}else {
		cout<<"00";
	}
	
	
return 0;
	}
