#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool op1, op2, op3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		op1=true;
		printf("1");
	}else
		printf("0");
	if(op1 && s1[0]==s2[0] && s1[1]==s2[1]){
		op2=true;
		printf("1");
	}else
		printf("0");
	if(op2){
		if((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')){
			printf("1");
			op3=true;
		}else if((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F')){
			printf("1");
			op3=true;
		}else
			printf("0");
	}else
		printf("0");
	if(op3){
		if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='F' && s2[2]=='D'))
			printf("1");
		else if((s1[2]=='B' && (s2[2]=='A' || s2[2]=='C')) || (s1[2]=='D' && s2[2]=='F'))
			printf("1");
		else
			printf("0");
	}else
		printf("0");
	return 0;
}
