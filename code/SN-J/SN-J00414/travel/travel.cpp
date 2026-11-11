#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=s1[0]-'0';
	int b=s1[1]-'0';
	int c=s2[0]-'0';
	int d=s2[1]-'0';
	int n=s1[2]-'A';
	int m=s2[2]-'A';
	if(c1==c2)
	{
		cout<<1;
		if(a==c&&b==d)
        {
	        cout<<1;
	        if(((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C'))&&((s2[2]=='D')||(s2[2]=='F')))
	        {
	        	cout<<0<<0;	
			}
			else
			{
				cout<<1;
				if(n-m==1||m-n==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
	    }
        else
        {
        	cout<<0<<0<<0;     
	    }
    }
    else
    {
    	cout<<0<<0<<0<<0;      
	}
    return 0;
}
