#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int num1=0,num2=0,num3=0,num4=0;
	char ch1,ch2;
	for(int i=0;i<2;i++) num1=num1*10+int(c1[i]-'0');
	for(int i=0;i<2;i++) num2=num2*10+int(c2[i]-'0');
	if(num1!=num2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	for(int i=0;i<2;i++) num3=num3*10+int(s1[i]-'0');
	for(int i=0;i<2;i++) num4=num4*10+int(s2[i]-'0');
	ch1=s1[2];
	ch2=s2[2];
	if(num3!=num4)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(ch1>ch2) swap(ch1,ch2);
	if(ch1=='A')
	{
		if(ch2=='B') cout<<"11";
		if(ch2=='C') cout<<"10";
		if(ch2=='D' || ch2=='F') cout<<"00";
	}
	if(ch1=='B')
	{
		if(ch2=='C') cout<<"11";
		if(ch2=='D' || ch2=='F') cout<<"00";
	}
	if(ch1=='C')
	{
		if(ch2=='D' || ch2=='F') cout<<"00";
	}
	if(ch1=='D')
	{
		if(ch2=='F') cout<<"11";
	}
	return 0;
}