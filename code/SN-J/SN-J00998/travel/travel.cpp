#include<bits/stdc++.h>
using namespace std;
string ca,cb,sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	int posa=(int)ca[0]-'0',posb=(int)cb[0]-'0';
	posa*=10;
	posb*=10;
	posa=posa+(int)ca[1]-'0';
	posb=posb+(int)cb[1]-'0';
	int cnta=(int)sa[0]-'0',cntb=(int)sb[0]-'0';
	cnta*=10;
	cntb*=10;
	cnta=cnta+(int)sa[1]-'0';
	cntb=cntb+(int)sb[1]-'0';
	char a=sa[2],b=sb[2];
	if(posa==posb){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(cnta==cntb){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(a<='C'&&a>='A'){
		if(b<='C'&&b>='A'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(b=='D'||b=='F'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	int len=abs((int)a-b);
	if(len==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
