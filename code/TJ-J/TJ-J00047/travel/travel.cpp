#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a=0,d=0,s=0,f=0,g,h,j,k,l,z;
	cin>>a>>s>>d>>f>>g>>h>>j>>k>>l>>z;
	if(a==h&&s==j)
	{
		cout << 1;
		if(d==k&&f==l)
		{
			cout << 1;
			if(g=='D' or g=='E' && z=='D' or z=='E')
	    	{
		    	cout << 1;
		    	cout << 1;
		    }
		    else if(g=='A' or g=='B' or g=='C' && z=='A' or z=='B' or z=='C')
		    {
		    	cout << 1;
		    	if(g=='A'&&z=='B' or z=='A'&&g=='B' or g=='C'&&z=='B' or z=='C'&&g=='B')
			    {
			    	cout << 1;
			    }
			    else
		    	{
			    	cout << 0;
		    	}
		    }
	    	else
		     {
		    	cout << 0;
		    	cout << 0;
	    	}
		}
		else{
			cout <<0;
			cout <<0;
			cout << 0;
		}
		
		
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
