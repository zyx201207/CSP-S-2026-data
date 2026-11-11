#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	string k1="",k2="";
	k1+=s1[0];k1+=s1[1];
	k2+=s2[0];k2+=s2[1];
	if(k1==k2){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	char t1=s1[2],t2=s2[2];
	if((t1<='C'&&t2<='C')||(t1>'C'&&t2>'C')){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(t1-'0'-(t2-'0'))==1){
		cout<<'1';
	}
	else cout<<'0';
	return 0;
}
