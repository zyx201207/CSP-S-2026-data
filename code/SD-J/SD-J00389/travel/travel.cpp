#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	int t=1;
	if(s1.length()==c1.length())
	{
	    for(int i=0;i<c1.length();i++)
	    {
	        if(s1[i]!=c1[i])
		    {
			    t=0;
		    }
	    }  	
	    cout<<t;
	}
	else
	{
		t=0;
		cout<<t;
	}
	int f=1;
	if(c2.length()==s2.length()&&t==1)
	{
		for(int i=0;i<c2.length()-1;i++)
		{
		    if(s2[i]!=c2[i])	
		    {
		    	f=0;
			}
		}cout<<f;
	}
	else
	{
		f=0;
		cout<<f;
	}
	int l=0;
	int r=0;
	int h=c2.length();
	if(f==1&&t==1)
	{
		if((c2[h-1]=='A'||c2[h-1]=='B'||c2[h-1]=='C')&&(s2[h-1]=='A'||s2[h-1]=='B'||s2[h-1]=='C'))
		{
		    l=1;	
		}
		if((c2[h-1]=='D'||c2[h-1]=='F')&&(s2[h-1]=='D'||s2[h-1]=='F'))
		{
			l=1;
			r=1;
		}
	}
	cout<<l;
	if(f==1&&t==1&&l==1)
	{
		if(s2[h-1]=='B'||c2[h-1]=='B')
		{
			r=1;
		}
	}
	cout<<r;
	return 0;
}
