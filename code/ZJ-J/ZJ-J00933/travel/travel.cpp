#include<bits/stdc++.h>
using namespace std;
char rcx[100],rzw[100],xcx[100],xzw[100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",&rcx);
	scanf("%s",&rzw);
	scanf("%s",&xcx);
	scanf("%s",&xzw);
	bool cx,p,c,zw;
	if(rcx[0]==xcx[0]&&rcx[1]==xcx[1])cx=true;
	else cx=false;
	if(cx&&rzw[0]==xzw[0]&&rzw[1]==xzw[1])p=true;
	else p=false;
	if(!cx||!p)c=false;
	else if(rzw[2]=='C'&&xzw[2]=='D'||rzw[2]=='D'&&xzw[2]=='C')c=false;
	else c=true;
	if(cx&&p&&c&&abs(rzw[2]-xzw[2])==1)zw=true;
	cout<<cx<<p<<c<<zw;
}