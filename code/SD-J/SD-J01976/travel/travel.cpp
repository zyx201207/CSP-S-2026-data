#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
bool flag=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2]>>s1[1]>>s1[2]>>s1[3];
	cin>>c2[1]>>c2[2]>>s2[1]>>s2[2]>>s2[3];
	if((c1[1]==c2[1])&&(c1[2]==c2[2])) printf("1");
	else flag=1,printf("0");
	if(((s1[1]==s2[1])&&(s1[2]==s2[2]))&&(flag==0)) printf("1");
	else flag=1,printf("0");
	if(((s1[3]>='A'&&s1[3]<='C'&&s2[3]>='A'&&s2[3]<='C')||(s1[3]>='D'&&s1[3]<='F'&&s2[3]>='D'&&s2[3]<='F'))&&(flag==0)) printf("1");
	else flag=1,printf("0");
	int a=s1[3]-'0',b=s2[3]-'0';
	if(abs(a-b)==1&&(flag==0)) printf("1");
	else flag=1,printf("0");
	return 0;
}
