#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char a,b,a1,b1;
	a=s1[0];
	a1=s1[1];
	b=s2[0];
	b1=s2[1];
	int flag1=0;
	int flag2=0;
	int cc=s1[2]-s2[2];
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		flag1=1;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		flag2=1;
	}
	if(c1==c2)
	{
		cout<<"1";
		if(a==b&&a1==b1)
	    {
		     cout<<"1";
		    if(flag1==flag2)
	        {
		        cout<<"1";
		        if(cc==1||cc==-1)
             	{
		            cout<<"1";
            	}
            	else
            	{
	            	cout<<"0";
             	}
        	}
	       else{
		        cout<<"0";
		        cout<<"0";
	           }
	    }
	    else
	    {
	    	cout<<"0";
	    	cout<<"0";
		     cout<<"0";
	    }
		
	}
	else
	{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}
//	cout<<cc;
	return 0;
 } 
