#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,out="";
	cin>>c1>>s1>>c2>>s2;
	int a,b,c,d;
	char e,f;
	a=(c1[0]-'0')*10+(c1[1]-'0');
	b=(s1[0]-'0')*10+(s1[1]-'0');
	c=(c2[0]-'0')*10+(c2[1]-'0');
	d=(s2[0]-'0')*10+(s2[1]-'0');
	e=s1[2];
	f=s2[2];
	if(a==c){
		out=out+"1";
	}else{
		out=out+"0";	
	}
	if(a==c&&b==d){
		out=out+"1";
	}else{
		out=out+"0";	
	}
	if(a==c&&b==d&&(((e=='A')&&(f=='B'))||((e=='B')&&(f=='A'))||((e=='B')&&(f=='C'))||((e=='C')&&(f=='B'))||((e=='D')&&(f=='F'))||((e=='F')&&(f=='D'))||(e=='A')&&(f=='C')||((e=='C')&&(f=='A')))){
		out=out+"1";
	}else{
		out=out+"0";	
	}
	if(a==c&&b==d&&(((e=='A')&&(f=='B'))||((e=='B')&&(f=='A'))||((e=='B')&&(f=='C'))||((e=='C')&&(f=='B'))||((e=='D')&&(f=='F'))||((e=='F')&&(f=='D')))){
		out=out+"1";
	}else{
		out=out+"0";	
	}
	cout<<out<<endl;
	return 0;
}

