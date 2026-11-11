#include<bits/stdc++.h>
using namespace std;
int ca,cb;
char sa[10],sb[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca!=cb){
		printf("0000");
		return 0;
	}
	if(sa[0]!=sb[0]||sa[1]!=sb[1]){
		printf("1000");
		return 0;
	}
	int xa=sa[2]-'A'+1,xb=sb[2]-'A'+1;
	if((xa<=3&&xb>3)||(xa>3&&xb<=3)){
		printf("1100");
		return 0;
	}
	if(xa<=3){
		if(abs(xa-xb)==1) printf("1111");
		else printf("1110");
	}
	else{
		printf("1111");
	}
	return 0;
} 
