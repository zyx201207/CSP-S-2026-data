#include<bits/stdc++.h>
using namespace std;
//É¾³ýfreopen×¢ÊÍ!!!
//²âÊÔÊä³öÉ¾³ý£¡£¡
string c1,s1,c2,s2;
long long p1,p2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;;
		return 0;
	}//³µÏá 
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
//	cout<<"p1 = "<<p1<<"  p2="<<p2<<endl;
	if(p1==p2){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	
	}//ÅÅ 
	a=s1[2];
	b=s2[2];
	if('A'<=a&&a<='C'){
		if('A'<=b&&b<='C'){
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
	}else if('D'<=a&&a<='F'){
		if('D'<=b&&b<='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}//²à 
	if(a=='A'){
		if(b=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(a=='B'){
		if(b=='A'||b=='C'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(a=='C'){
		if(b=='B'){
			cout<<1;
		}else {
			cout<<0;
		}
	}else if(a=='D'){
		if(b=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}//ÅÔ±ß 
	return 0;
}
