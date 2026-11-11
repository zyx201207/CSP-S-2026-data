#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int f,c,p;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    f=0;
    for(int i=0;i<2;i++)
    {
    	if(c1[i]!=c2[i])
    	{
    	     f=1;
		}
	}
	if(f==0)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	f=0;
	for(int i=0;i<2;i++)
    {
    	if(s1[i]!=s2[i])
    	{
    	     f=1;
		}
	}
	if(f==0)
	{
		p=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F')&&(s1[2]>='D'&&s1[2]<='F'))
	{
		cout<<1;
		c=1;
	}
	else
	{
		cout<<0;
	}
	if(p==1&&c==1&&abs(s1[2]-s2[2])==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}