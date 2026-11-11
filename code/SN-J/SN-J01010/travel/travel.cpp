#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char b[4],d[4];
	int a,c;
	scanf("%d",&a);
	cin >> b[1];
	cin>> b[2];
	cin >> b[3];
	scanf("%d",&c);
	cin >> d[1];
	cin>> d[2];
	cin >> d[3];
	if(a==c){
		printf("1");
	}
	else {
		printf("0000");
		return 0;
	}
		if((b[1]==d[1])&&(b[2]==d[2])){
		printf("1");	
		if((((b[3]=='A')&&(d[3]=='B'))||((b[3]=='B')&&(d[3]=='A'))||((b[3]=='C')&&(d[3]=='A'))||((b[3]=='A')&&(d[3]=='C'))||((b[3]=='D')&&(d[3]=='F'))||((b[3]=='F')&&(d[3]=='D')))){
		printf("1");
	}
	else {
		printf("0");
	}
		if((((b[3]=='A')&&(d[3]=='B'))||((b[3]=='B')&&(d[3]=='A'))||((b[3]=='C')&&(d[3]=='B'))||((b[3]=='B')&&(d[3]=='C'))||((b[3]=='D')&&(d[3]=='F'))||((b[3]=='F')&&(d[3]=='D')))){
		printf("1");
	}
	else {
		printf("0");
	}
	}
	else {
		printf("000");
		
	}

	return 0;	
}
	
	
	
	
	
	

