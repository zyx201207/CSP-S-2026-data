#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char zm1,zm2;
int zuo1,zuo2;
int f(string s){
	int com=0,m=0;
	while(m<=1){
		com=com*10+(s[m]-'0');
		++m;
	}
	return com;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>c1>>s1>>c2>>s2;
	zuo1=f(s1);
	zuo2=f(s2);
	zm1=s1[s1.size()-1];
	zm2=s2[s2.size()-1];
	if(c1==c2){
		cout<<"1";
		if(zuo1==zuo2){
			cout<<"1";
			if((zm1>'C'&&zm2>'C')||(zm1<='C'&&zm2<='C')){
				cout<<"1";
				if((zm1=='A'&&zm2=='C')||(zm2=='A'&&zm1=='C')){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
