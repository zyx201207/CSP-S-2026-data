#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)printf("1");
	else{
		printf("0000");
		return 0;
	}
	if(b1[0]==b2[0]&&b1[1]==b2[1])printf("1");
	else{
		printf("000");
		return 0;
	}
	if(((b1[2]=='F'||b1[2]=='D')&&(b2[2]=='F'&&b2[2]=='D'))||((b1[2]!='F'&&b1[2]!='D')&&(b2[2]!='F'||b2[2]!='D')))printf("1");
	else{
		printf("00");
		return 0;
	}
	if(b1[2]+1==b2[2]||b1[2]-1==b2[2])printf("1");
	else printf("0");
	return 0;
}


