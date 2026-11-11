#include <bits/stdc++.h>
using namespace std;
int q,w; 
string a[10],b[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q;
    for(int i=1;i<=3;i++)
	{
		cin>>a[i];
	}
	cin>>w;
	for(int i=1;i<=3;i++)
	{ 
		cin>>b[i];
	}
	if(q==w)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
	if((a[1]==b[1]) && (a[2]==b[2]))
	{
			cout<<"1";
	}
	else
	{
			cout<<"0";
	}
	if(a[3] != b[3])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
		if(a[3] !=b[3])
	    {
		    cout<<"1";
	    }
	     else
	    {
		      cout<<"0";
	    }
	 } 
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
