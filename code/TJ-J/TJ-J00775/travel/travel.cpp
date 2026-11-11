#include<bits/stdc++.h>
using namespace std;
long long a1,b1,e1=0,e2=0;
string a2,b2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		printf("0000");
		return 0;
	}else{
		printf("1");
	}
	c1=a2[0];
	c1=c1+a2[1];
	
	c2=b2[0];
	c2=c2+b2[1];
	if(c1==c2){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	char d1=a2[2];
	char d2=b2[2];
	if(d1=='F'||d1=='D'){
		e1=2;
	}else if(d1=='A'||d1=='B'||d1=='C'){
		e1=1;
	}
	if(d2=='F'||d2=='D'){
		e2=2;
	}else if(d2=='A'||d2=='B'||d2=='C'){
		e2=1;
	}
	if(e1==e2){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if(abs(int(d1)-int(d2))==1){
		printf("1");
	}else{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
