#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	/*freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);*/
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) printf("1");
	else{
		printf("0000");
		return 0;
	}
	int a=(a2[0]-'0')*10+a2[1]-'0';
	int b=(b2[0]-'0')*10+b2[1]-'0';
	if(a==b) printf("1");
	else{
		printf("000");
		return 0;
	}
	char x=a2[2],y=b2[2];
	if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
		printf("1");
		if((x=='A'&&y=='C')||(x=='C'&&y=='A')) printf("0");
		else printf("1");
	}else if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
		printf("11");
		return 0;
	}else printf("00");
	return 0;
}
