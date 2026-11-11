#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;



int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
    string str="";
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		string s;
		cin>>x>>s;
		for(long long j=1;j<=x;j++)
		{
			str=str+s; 
		}
	}
	
	bool fl=0;
	if(str.size()%2!=0) fl=1;
    long long c=str.size()/2;
    string q="";
    string p="";
    
    if(fl=0)
    {
    	for(int i=0;i<c;i++)
	    {
		    q=q+str[i];
	    }
    	for(int i=str.size()-1;i>=c;i--)
    	{
    		p=p+str[i];
		}
	}
	else
	{
    	for(int i=0;i<c;i++)
	    {
		    q=q+str[i];
	    }
    	for(int i=str.size()-1;i>c;i--)
    	{
    		p=p+str[i];
	
	    }
	}
	
	long long cnt=0;
	for(int i=0;i<c;i++)
	{
		if(q[i]!=p[i])
		{
			cnt++;
		}
	}
	
	cout<<cnt;
	
	
	
	
	return 0;
}
