#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(string x,string y){
	int len=x.size();
	for(int i=0;i<len;i++){
		if(x[i]!=y[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(check(c1,c2)){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	if(s1[1]==s2[1]){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if((((s1[2]=='F' || s2[2]=='D') && (s2[2]=='F' || s2[2]=='D')) || ((s1[2]=='C' || s1[2]=='B' || s1[2]=='A') && (s2[2]=='C' || s2[2]=='B' || s2[2]=='A')))
	&& !((s1[2]=='C' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='C'))){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if((s1[2]=='F' && s2[2]=='D')
	|| (s1[2]=='D' && s2[2]=='F')
	|| (s1[2]=='C' && s2[2]=='B')
	|| (s1[2]=='B' && s2[2]=='C')
	|| (s1[2]=='B' && s2[2]=='A')
	|| (s1[2]=='A' && s2[2]=='B')){
		printf("1");
	}else{
		printf("0");
		return 0;
	}
	return 0;
}
