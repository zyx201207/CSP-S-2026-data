#include<bits/stdc++.h>
using namespace std;
long long int i,m,n,flag=1,s;
string c1,s1,c2,s2;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
		cin>>c1>>s1>>c2>>s2;
		if(c1==c2)
		{
		printf("1");s++;
		for(i=0;i<=1;i++)
		{
		a=s1[i]; 
		b=s2[i];
		if(a!=b)
		{
		    flag=0;
			cout<<"0";s++;
			break;
			
		}
		}
		if(flag==1)
		{
		cout<<"1";
		s++;

		a=s1[2];b=s2[2];
	if(a<='C'&&b<='C'||a>'C'&&a<='F'&&b>'C'&&b<='F')
	{
	cout<<"1";
	s++;}
	else
	cout<<"0";s++;
		if(a<='C'&&b<='C'||a>'C'&&a<='F'&&b>'C'&&b<='F')
		{
			if(a<='C'&&b<='C')
			if(a-b==1||a-b==-1)
			cout<<"1";
			else
			if(a=='D'||a=='F')
			cout<<"1";
			else
			cout<<"0";
			s++;
		}
	
	}
}

while(s<4)
{
cout<<"0";
s++;
}
	return 0;
 } //02 01A 02 01B
