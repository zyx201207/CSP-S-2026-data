#include<bits/stdc++.h> 
using namespace std;
int main()
{ 
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n,m;
	string s,a;
	cin>>n>>s>>m>>a;
	if(n==m)
	{
		cout<<1;
		if(s[0]==a[0]&&s[1]==a[1])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		if('A'<=s[2]<='C'&&'A'<=a[2]<='C')
		{
			
			if((s[2]=='A')&&(a[2]=='B'))
			{
				cout<<1;
				
			}
			else
			{
				cout<<0;
			}
		}
	    if('A'<=s[2]<='C'&&'A'<=a[2]<='C')
		{
			if((s[2]=='B')&&(a[2]=='C'))
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			if(s[2]=='D'&&a[2]=='F')
		    {
			    if(s[0]==a[0]&&s[1]==a[1])
			    {
			        cout<<1;
			    }
			    else
			    {
			    	cout<<0;
				}
		    }
		}
	} 
	else
	{
		cout<<0<<0<<0<<0;
	}
	
	
}
