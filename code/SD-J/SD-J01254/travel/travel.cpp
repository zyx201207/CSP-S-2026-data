#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	int f=0;
	if(c1==s1){
		f=1;
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	string z1="",z2="";
	int z=0;
	z1=c2[0]+c2[1];
	z2=s2[0]+s2[1];
	if(z1==z2&&f==1){
		z=1;
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	int s=0,c=0;
	int o=0;
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
    	s=1;
	}
	    if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
    	c=1;
	}
	if(s==1&&c==1){
		cout<<"1";
		o=1;
	}
	s=0,c=0;
	if(s2[2]=='D'||s2[2]=='F'){
		s=1;
	}
		if(c2[2]=='D'||c2[2]=='F'){
		c=1;
	}
	if(s==1&&c==1){
		cout<<"1";
		o=1;
	}
	if(o==0){
		cout<<"00";
		return 0;
	}
	if(s2[2]+1==c2[2]||s2[2]-1==c2[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 

