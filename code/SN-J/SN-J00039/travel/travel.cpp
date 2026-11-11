#include <bits/stdc++.h>
using namespace std;
char a[20];
char b[20];
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i = 1;i <= 5;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i <= 5;i++)
	{
		cin>>b[i]; 
	}
	if(a[1] == b[1] && a[2] == b[2])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a[3] == b[3] && a[4] == b[4] && a[1] == b[1] && a[2] == b[2])
	{
		cout<<1;
		if(a[5] > 'C' && b[5] > 'C')
    	{
	    	cout<<1;
    	}
	    else if(a[5] <'D' && b[5] < 'D')
	    {
	    	cout<<1;
    	}
	    else
     	{
    		cout<<0;
    	}
    	if(a[5] != b[5])
    	{
    		if(a[5] > 'C' && b[5] > 'C')
    		{
    			cout<<1;
    		} 
    		else if(a[5] < 'D' && b[5] < 'D' && (a[5] == 'B' || b[5] == 'B'))
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
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}  
