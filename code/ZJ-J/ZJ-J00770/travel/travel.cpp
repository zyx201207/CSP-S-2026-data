#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool check(char x,char y){
	if(x<='C'&&y<='C')return 1;
	if(x>='D'&&y>='D')return 1;
	return 0;
}
bool check1(char x,char y){
	if(abs(x-y)==1)return 1;
	else if(x=='D'&&y=='F'||x=='F'&&y=='D')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		printf("1");
		int a=(a2[0]-'0')*10+a2[1]-'0';
		int b=(b2[0]-'0')*10+b2[1]-'0';
		if(a==b){
			printf("1");
			if(check(a2[2],b2[2])){
				printf("1");
				if(check(a2[2],b2[2]))printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
