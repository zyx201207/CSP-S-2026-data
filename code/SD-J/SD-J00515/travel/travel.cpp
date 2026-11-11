#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool x=0,y=0,z=0;
	if(c1==c2){
		cout<<1;
		x=1;
	}else{
		cout<<0;
	}
	string tmpr="",tmpx="";
	tmpr+=s1[0];
	tmpr+=s1[1];
	tmpx+=s2[0];
	tmpx+=s2[1];
	if(x&&tmpr==tmpx){
		cout<<1;
		y=1;
	}else{
		cout<<0;
	}
	char a=s1[2],b=s2[2];
	if(y&&((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='B'&&b=='A')||(a=='C'&&b=='A')||(a=='C'&&b=='B'))){
		cout<<1;
		z=1;
	}else{
		cout<<0;	
	}
	if(z&&((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='A'&&b=='B')||(a=='B'&&b=='C'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
