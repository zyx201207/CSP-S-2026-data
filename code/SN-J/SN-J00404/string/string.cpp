#include <iostream>
using namespace std;
int main()
{
    int l;
    cin>>l;
    int sum=0;
    string s[l];
    for(int i=0;i<=l-1;i++)
    {
    	cin>>s[i];
	}
	if((l+1)%2==1)
	{
		for(int j=0;j<=(l+1)/2;j++)
	    {
	    	for(int h=1;h<=l;h++)
		    {
		    	s[j]=s[l-j];
		        sum++;
	        }
	    }
	    cout<<sum;
    }
    else
    {
    	for(int k=0;k<=(l+1)/2;k++)
    	{
    		for(int g=1;g=l;g++)
    		{
    		    s[k]=s[l-k];
    		    sum++;
    	    }
		}
		cout<<sum;
	}
	return 0;
 }
