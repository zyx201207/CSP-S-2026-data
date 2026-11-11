#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
char ch,ch1,ch2,ch3,ch4,ch5;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a=1;
	}
	ch=s1[0];
	ch1=s1[1];
	ch2=s2[0];
	ch3=s2[1];
	if(ch==ch2&&ch1==ch3&&a==1)
	{
		b=1;
	}
	ch4=s1[2];
	ch5=s2[2];
	if(a==1&&b==1&&ch4==ch5) c=1;
	else if(ch==ch2&&ch1==ch3&&c1==c2&&(ch4=='D'||ch4=='F')&&(ch5=='D'||ch5=='F'))c=1;
	else if(ch==ch2&&ch1==ch3&&c1==c2&&(ch4=='A'||ch4=='B'||ch4=='C')&&(ch5=='A'||ch5=='B'||ch5=='C'))c=1;	
	if(a==1&&b==1&&c==1&&(ch4+1==ch5||ch4-1==ch5))d=1;
	cout<<a<<b<<c<<d;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}