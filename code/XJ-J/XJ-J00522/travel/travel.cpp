#include<bits/stdc++.h>
using namespace std;

int main()
{
	preopen(travel.in,'w',stdin);
	preopen(travel.out,'r',stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=4;i++)
	{
    	if(c1==c2)
    	{
    		cout<<1;
    		if(s1[1]==s2[1] && s1[2]==s2[2])
    		{
	    		cout<<12;
	    		if(('A'<=s1[3]<='C' && 'A'<=s2[3]<='C') || ('D'<=s1[3]<='E' && 'D'<=s2[3]<='E'))
	    		{
	    			cout<<12;
	    			if(s1[3]-s2[3]==1 || s2[3]-s1[3]==1)
	    			{
	    			    cout<<13;
	        		}
	    			else
	    			{
	    				cout<<0;
					}
	    		}
	    		else
	    		{
	    			cout<<0;
				}
	    	}
	    	else
	    	{
	    		cout<<0;
			}
    	}
    	else
    	{
    		cout<<0;
		}
    }
	return 0;
}