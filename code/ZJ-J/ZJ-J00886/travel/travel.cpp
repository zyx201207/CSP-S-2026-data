#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) printf("1");
	else printf("0000"),exit(0);
	if(((s1[0]-'0')*10+s1[1]-'0')==((s2[0]-'0')*10+s2[1]-'0')) printf("1");
	else printf("000"),exit(0);
	if(s1[2]=='A'){
		if(s2[2]=='B') printf("11"),exit(0);
		if(s2[2]=='C') printf("10"),exit(0);
		if(s2[2]=='D'||s2[2]=='F') printf("00"),exit(0);
	}
	if(s1[2]=='B'){
		if(s2[2]=='A') printf("11"),exit(0);
		if(s2[2]=='C') printf("11"),exit(0);
		if(s2[2]=='D'||s2[2]=='F') printf("00"),exit(0);
	}
	if(s1[2]=='C'){
		if(s2[2]=='A') printf("10"),exit(0);
		if(s2[2]=='B') printf("11"),exit(0);
		if(s2[2]=='D'||s2[2]=='F') printf("00"),exit(0);
	}
	if(s1[2]=='D'){
		if(s2[2]=='F')printf("11"),exit(0);
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') printf("00"),exit(0);
	}
	if(s1[2]=='F'){
		if(s2[2]=='D') printf("11"),exit(0);
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') printf("00"),exit(0);
	}
	return 0;
} 
