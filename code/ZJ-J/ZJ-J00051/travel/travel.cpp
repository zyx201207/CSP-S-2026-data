#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,t1="00",t2="00";

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	t1[0]=s1[0],t1[1]=s1[1];
	t2[0]=s2[0],t2[1]=s2[1];
	if(c1==c2)
		printf("1");
	else
		printf("0");
	if(c1==c2&&t1==t2)
		printf("1");
	else
		printf("0");
	if(c1==c2&&t1==t2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
		printf("1");
	else
		printf("0");
	if(c1==c2&&t1==t2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
		printf("1");
	else
		printf("0");
	return 0;
}
