#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char s3,s4;
	s3=s1[2];
	s4=s2[2];
	s1.erase(2);
	s2.erase(2);
	if(c1==c2)
	{
		cout<<"1";
		if(s1==s2)
	    {
		    cout<<"1";
		    if(s3<='C'&&s4<='C'||s3>='D'&&s4>='D')
	        {
		        cout<<"1";
		        if(s3-1==s4||s3+1==s4)
	            {
		            cout<<"1";
	            }
	            else
	            {
		            cout<<"0";
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
