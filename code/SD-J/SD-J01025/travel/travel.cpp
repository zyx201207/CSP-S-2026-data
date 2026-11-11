#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct info {
	string x,y;
}a,b;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.x>>a.y>>b.x>>b.y;
	int ok=0;
	if (a.x[0]==b.x[0]&&a.x[1]==b.x[1]) 
		ok=1;
	else ok=0;
	if (!ok) {
		printf("0000\n");
		return 0;
	}
	printf("1");
	if (a.y[0]==b.y[0]&&a.y[1]==b.y[1]) 
		ok=1;
	else ok=0;
	if (!ok) {
		printf("000\n");
		return 0;
	}
	printf("1");
	char awa1=a.y[2],awa2=b.y[2];
	if (awa1>awa2) swap(awa1,awa2);
	if (awa1<='C'&&'D'<=awa2) ok=0;
	else ok=1;
	if (!ok) {
		printf("00\n");
		return 0;
	}
	printf("1");
	if (awa1=='D'&&awa2=='F') ok=1;
	else if (awa1=='A'&&awa2=='C') ok=0;
	else ok=1;
	printf("%d\n",ok);
	return 0;
}
/*
08:39 ~ 08:46
Trick||Treat!
*/
