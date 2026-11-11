#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f(char a,char b){
	if(a>b){
		char c=b;
		b=a;
		a=c;
	}
	return (b-a==1)||(b=='F'&&a=='D');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		printf("0000");
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		printf("1000");
		return 0;
	}
	if((s1[2]=='D'&&s2[2]!='F')||(s1[2]=='F'&&s2[2]!='D')||(s1[2]!='D'&&s2[2]=='F')||(s1[2]!='F'&&s2[2]=='D')){
		printf("1100");
		return 0;
	}
	if(f(s1[2],s2[2])){
		printf("1111");
	}else{
		printf("1110");
	}
	return 0;
}

