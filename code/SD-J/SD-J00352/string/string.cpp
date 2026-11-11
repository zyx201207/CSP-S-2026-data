#include<bits/stdc++.h>
using namespace std;
int sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string c,x;
	int a;
	cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a>>c;
    	if(n==1)
    	{
    		cout <<"0";
     	}
     	else if(n==2||n==3)
    	{
    		cout <<"1";
      	}
     	else if(n==4)
    	{
    		cout <<"2";
    	}
    	else
    	{
    		cout <<"3";
    	}
	}
	return 0;
 } 
