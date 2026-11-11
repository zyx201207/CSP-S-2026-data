#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,c2,s,s2;
	cin>>c>>c2>>s>>s2;
	int o=c2[2]-'A';
	int o1=s2[2]-'A';
	if (c==s)
	{
		cout<<1;
		if ((c2[0]==s2[0])&&(c2[1]==s2[1]))
	    {
		    cout<<1;
			if ((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||c2[2]=='C'))
	        {
		        cout<<1;
			    if (o-o1==1)
			    {
				    cout<<1;
						  
			    }
			    else
				{
					cout<<0;
							
				} 
		    }	
	        else if ((c2[2]=='D'||c2[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
	        {
		        cout<<1;
		        cout<<1;
	        }
	        else
	        {
		        cout<<0;
		        cout<<0;
	        }
	    }
		else
	    {
		    cout<<0;
		    cout<<0;
		    cout<<0;
	    }

    }
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
	
}
