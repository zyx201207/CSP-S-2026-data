#include <bits/stdc++.h>
using namespace std;
string cn,sn,cn2,sn2;
char kkk[6]={'A','B','C','D','F'};
void check()
{
	string numa,numb;
	if(cn[0]=='0') numa=cn[1];
	else numa=cn;
	if(cn2[0]=='0') numb=cn2[1];
	else numb=cn2;
	string nn,nn1;
	if(sn[0]=='0') nn=sn[1];
	else nn=sn[0]+sn[1];
	if(sn2[0]=='0') nn1=sn2[1];
	else nn1=sn2[0]+sn2[1];
	char ch=sn[2],ch1=sn2[2];
	string ss,ss1;
	if(ch=='A'||ch=='B'||ch=='C') ss="left";
	else ss="right";
	if(ch1=='A'||ch1=='B'||ch1=='C') ss1="left";
	else ss1="right";
	if(numa==numb) cout<<1;
	else cout<<0;
	if(nn==nn1&&numa==numb) cout<<1;
	else cout<<0;
	if(nn==nn1&&ss==ss1&&numa==numb) cout<<1;
	else cout<<0;
	if((ch==ch1+1||ch==ch1-1)&&ss==ss1&&nn==nn1&&numa==numb) cout<<1;
	else cout<<0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cn>>sn>>cn2>>sn2;
	check();
	return 0;
}

