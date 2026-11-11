#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,r="",w="";
	char r1,w1;
	bool flag=1,flag1=1;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')   r+=s1[i];
		else  r1+=s1[i];
	}
	for(int i=0;i<s2.size();i++) 
	{
		if(s2[i]>='0'&&s2[i]<='9')          w+=s2[i];
		else  w1+=s2[i];
	}
	if(c1==c2)   
	{
		cout<<'1';                               
	}
	else { 
		cout<<'0';
		flag1=0; 
	} 
	if(r==w&&flag1==1)   cout<<'1';
	else {
		cout<<'0';
		flag1=0;
	}
	if(  (((w1>='A'&&w1<='C')&&(r1>='A'&&r1<='C'))  || ((w1>='D'&&w1<='F')&&(r1>='D'&&r1<='F'))) && flag1==1 ){
		cout<<'1';
		flag=0;
	}
	else 
	{
		cout<<'0';
		flag1=0;
	}
	if((w1+1==r1||r1+1==w1)&&flag==0)   cout<<'1';
	else cout<<'0';

	
	return 0;
} 
