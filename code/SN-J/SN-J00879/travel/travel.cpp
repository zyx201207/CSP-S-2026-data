#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r2,x2,r1,x1;
    getline(cin,r1);
    getline(cin,r2);
    getline(cin,x1);
    getline(cin,x2);
    if(r1==x1)
    {
    	cout<<1;
	}
	else
	{
		cout<<0;
	}
	for(int i=0;i<r2.size();i++)
	{
		cin>>a[i];
	}
	for(int j=0;j<x2.size();j++)
	{
		cin>>b[j];
	}
	for(int i=0;i<3;i++)
	{
		if(i!=2)
		{
			if(a[i]==b[i])
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
			if(int(a[i])-int(b[i])==1&||int(b[i])-int(a[i])==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
    return 0;
}
