#include<bits/stdc++.h>
using namespace std;
char a1[100],a2[100],b1[100],b2[100];
string c,d;
char e=a2[2],f=b2[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0]&&a1[1]==b1[1]){
		cout<<"1";	
	}
	else{
		cout<<"0000";
		return 0;
	} 
	c=c+a2[0]+a2[1];
	d=d+b2[0]+b2[1];
	if(c==d){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	int g=0;
	if(e<='C'&&f<='C')g=1;
	if(e<='C'&&f<='C'||e>='D'&&f>='D'){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(g==1){
		if(e!='C'&&e!='A'||f!='A'&&f!='C'){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"1";
	}
}
