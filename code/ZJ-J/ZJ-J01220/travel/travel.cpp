#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("1");
	}
	else{
		printf("0000");
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		printf("1");
	}
	else{
		printf("000");
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		printf("1");
	}
	else{
		printf("00");
		return 0;
	}
	int x=s1[2]-'A';
	int y=s2[2]-'A';
	if(abs(x-y)==1){
		printf("1");
	}
	else{
		printf("0");
	}
	return 0;
} 
