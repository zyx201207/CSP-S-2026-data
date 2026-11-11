#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string c="";
    for(long long i=0;i<n;i++)
    {
    	long long a;
		char b;
    	cin>>a>>b;
    	for(long long j=0;j<a;j++)
    	{
    		c+=b;
		}
	}
	long long r=c.size()-1;
	long long sum=0;
	for(long long i=0;i<c.size()/2;i++)
	{
		if(c[i]!=c[r])
		{
			sum++;
		}
		r--;
	}
	cout<<sum;
	return 0;
}
