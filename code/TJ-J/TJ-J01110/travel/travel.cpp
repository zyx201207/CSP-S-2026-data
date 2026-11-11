#include<bits/stdc++.h>
using namespace std;
char aa,ab,ba,bb,bc,ca,cb,da,db,dc;
int main() {
	//114514 debate 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%c%c %c%c%c %c%c %c%c%c",&aa,&ab,&ba,&bb,&bc,&ca,&cb,&da,&db,&dc);

	if(aa==ca&&ab==cb) {
		printf("1");
	} else {
		printf("0000");
		return 0;
	}
	if(ba==da&&bb==db) {
		printf("1");
	} else {
		printf("000");
		return 0;
	}
	if((bc=='A'||bc=='B'||bc=='C')&&(dc=='A'||dc=='B'||dc=='C')) {
		printf("1");
	} else if((bc=='D'||bc=='E')&&(dc=='E'||dc=='D')) {
		printf("1");
	} else {
		printf("00");

		return 0;
	}
	if(bc=='A'&&dc=='B') {
		printf("1");
	} else if (bc=='C'&&dc=='A') {
		printf("0");
	} else if (bc=='A'&&dc=='C') {
		printf("0");
	} else 	if(bc=='B'&&dc=='C'||dc=='A') {
		printf("1");
	} else 	if(bc=='C'&&dc=='B') {
		printf("1");
	} else 	if(bc=='D'&&dc=='E') {
		printf("1");
	} else 	if(bc=='E'&&dc=='D') {
		printf("1");
	} else {
		printf("0");
	}
	return 0;
}
