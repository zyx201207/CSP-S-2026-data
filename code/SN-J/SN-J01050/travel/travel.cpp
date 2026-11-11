#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char t1=char(s1[2]);
	char t2=char(s2[2]);
	if(c1==c2){
		cout<<"1";
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
    if((s1[0]==s2[0])&&(s1[1]==s2[1])){
		cout<<"1";
	}
	if((s1[0]!=s2[0])||(s1[1]!=s2[1])){
		cout<<"000";
		return 0;
	}
	if(s1==s2){
		cout<<"00"; 
		return 0;
	}else if((t1>='A'&&t1<='C')&&(t2>='A'&&t2<='C')&&(t1!=t2)){
		cout<<"1";
	}else if((t1>='D'&&t1<='F')&&(t2>='D'&&t2<='F')&&(t1!=t2)){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[3]-s2[3])=='1'){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
