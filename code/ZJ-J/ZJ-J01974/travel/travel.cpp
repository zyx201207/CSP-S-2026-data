#include<bits/stdc++.h>
using namespace std;
string s,ss,s2,ss2;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>s2>>ss2;
	if(ss[2]=='D'){
		ss[2]='E';
	}
	if(ss2[2]=='D'){
		ss2[2]='E';
	}
	if(s==s2){
		cout<<1;
		f=1;
	}else{
		cout<<0;
		f=0;
	}
	if((ss[0]==ss2[0]&&ss[1]==ss2[1])&&f){
		cout<<1;
		f=1;
	}else{
		cout<<0;
		f=0;
	}
	if((ss[2]>='A'&&ss[2]<='C'&&ss2[2]>='A'&&ss2[2]<='C'||ss[2]>='E'&&ss[2]<='F'&&ss2[2]>='E'&&ss2[2]<='F')&&f){
		cout<<1;
		f=1;
	}else{
		cout<<0;
		f=0;
	}
	if((ss[2]+1==ss2[2]||ss[2]-1==ss2[2])&&f){
		cout<<1;
		f=1;
	}else{
		cout<<0;
		f=0;
	}
	return 0;
}
