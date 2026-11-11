#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='D')s1[2]='E';
	if(s2[2]=='D')s2[2]='E';
	if(c1==c2){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	s+=s1[0];
	s+=s1[1];
	t+=s2[0];
	t+=s2[1];
	if(s==t){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='E'&&s2[2]>='E'){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if(abs(int(s1[2]-s2[2]))==1){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}
