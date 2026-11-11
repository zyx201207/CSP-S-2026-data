#include<iostream>
#include<cstring>
#include<cstdio>
int a1,a2;
char s1[10],s2[10];
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1;
	for(int i=0;i<3;i++)
	cin>>s1[i];
	cin>>a2;
	for(int i=0;i<3;i++)
	cin>>s2[i];
	char c1=s1[2],c2=s2[2];
	int b1=(s1[0]-'0')*10+s1[1]-'0',b2=(s2[0]-'0')*10+s2[1]-'0';
	if(a1==a2) cout<<1;
	else cout<<0;
	if(a1==a2 and b1==b2) cout<<1;
	else cout<<0;
	if(a1==a2 and b1==b2 and ((c1<='C' and c2<='C') or (c1>='D' and c2>='D'))) cout<<1;
	else cout<<0;
	if(a1==a2 and b1==b2 and (c1+1==c2 or c1-1==c2) and ((c1<='C' and c2<='C') or (c1>='D' and c2>='D')))cout<<1;
	else cout<<0;
	return 0;
 } 
