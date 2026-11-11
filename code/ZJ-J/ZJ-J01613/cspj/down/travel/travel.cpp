#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char s1,s2;
	cin>>a1>>b1>>s1>>a2>>b2>>s2;
	if(a1==a2)
	{
		cout<<1; 
		if(b1==b2)
		{
		  cout<<1;
	 		if(s1=='A'&&s2=='B'||s1=='A'&&s2=='C'||s1=='B'&&s2=='A'||s1=='B'&&s2=='C'||s1=='C'&&s2=='A'||s1=='C'&&s2=='B'||s1=='D'&&s2=='F'||s1=='F'&&s2=='D')
			{
			  cout<<1;
				if(s1=='A'&&s2=='B'||s1=='B'&&s2=='A'||s1=='B'&&s2=='C'||s1=='C'&&s2=='B'||s1=='D'&&s2=='F'||s1=='F'&&s2=='D')
		    {
				  cout<<1;
				}
				else
				{
				  cout<<0;
				}
			}
			else
			{
		    cout<<"00";
			}
		} 
	 	else
		{
		  cout<<"000";
		}
	} 
	else
	{
		cout<<"0000";
	}
	return 0;
}
