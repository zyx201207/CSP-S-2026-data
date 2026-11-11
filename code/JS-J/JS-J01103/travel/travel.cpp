#include<bits/stdc++.h>
using namespace std;

char c1[10],s1[10],c2[10],s2[10];

bool check(const char &x,const char &y){
	if(x=='A'){
		return y=='B'||y=='C';
	}
	if(x=='B'){
		return y=='A'||y=='C';
	}
	if(x=='C'){
		return y=='A'||y=='B';
	}
	if(x=='D'){
		return y=='F';
	}
	if(x=='F'){
		return y=='D';
	}
}

bool xl(const char &x,const char &y){
	if(x=='A'){
		return y=='B';
	}
	if(x=='B'){
		return y=='A'||y=='C';
	}
	if(x=='C'){
		return y=='B';
	}
	if(x=='D'){
		return y=='F';
	}
	if(x=='F'){
		return y=='D';
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
	if(c1[1]!=c2[1]||c1[2]!=c2[2]){
		printf("0000");
	}else{
		printf("1");
		if(s1[1]!=s2[1]||s1[2]!=s2[2]){
			printf("000");
		}else{
			printf("1");
			if(!check(s1[3],s2[3])){
				printf("00");
			}else{
				printf("1");
				if(!xl(s1[3],s2[3])){
					printf("0");
				}else{
					printf("1");
				}
			}
		}
	}
}