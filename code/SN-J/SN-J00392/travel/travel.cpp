#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s>>s1>>s2>>s3;
	int x=0,x1=0,x2=0,x3=0;
	char c,c1;
	for(int i=0;i<2;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
	    x=x*10+(int)s[i]-48;	
	}
	//cout<<x<<'\n';
	for(int i=0;i<3;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')x1=x1*10+(int)s1[i]-48;	
		else c=s1[i];
	}
	//cout<<x1<<' '<<c<<'\n';
	for(int i=0;i<2;i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
	    x2=x2*10+(int)s2[i]-48;	
	}
	//cout<<x2<<'\n';
	for(int i=0;i<3;i++)
	{
		if(s3[i]>='0'&&s3[i]<='9')x3=x3*10+(int)s3[i]-48;	
		else c1=s3[i];
	}
	//cout<<x3<<' '<<c1<<'\n';
	if(x!=x2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<'1';
		if(x1!=x3)
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<'1';
			if(((c=='A'||c=='B'||c=='C')&&(c1=='A'||c1=='B'||c1=='C'))||((c=='D'||c=='F')&&(c1=='D'||c1=='F')))
			{
				cout<<'1';
				if((((int)c+1)==((int)c1)&&(c!='c'&&c1!='D'))||(((int)c1+1)==((int)c)&&(c!='D'&&c1!='C')))
				{
					cout<<'1';

				}
				else
				{
					cout<<'0';
				}				
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
	}
return 0;
}
