#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1,s1,c2,s2;
	for(int i=01;i<=18;i++)
	{
	    for(int i=1;i<=5;i++)
	    {
	    	if(c1 == c2)
	    	{
	    		cout<<1;
			}
			if(s1 == s2)
			{
				cout<<1;
			}
			if(c1==s1 && c2==s2)
			{
				cout<<1;
			}
			if(s1 +'1'= s2)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
	         if(c1==c2 && s1 == s2 && c1==s1==s2==c2 && s1 +'1'=s2)
	         {
	         	cout<<1111;
			 }
			 else
			 {
			 	cout<<0000;
			 }
	    }
	}
	return 0;
}