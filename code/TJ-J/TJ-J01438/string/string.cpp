#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	string a,s;
	long long sum=0;
	long long num=0;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin >>x;
		cin >>a[i];
		sum+=x;
		for(int j=1;j<=x;j++)
		{
			s+=a[i];
		}
	}
	if(sum%2==0)
	{
		for(int i=0;i<sum/2;i++)
	    {
		    if(s[i]!=s[sum-1-i])
		    {
			    num++;
		    }
	    }
	}
	else
	{
		for(int i=0;i<sum;i++)
		{
			if(s[i]==s[sum-1-i])
			{
				break;
			}
			if(s[i]!=s[sum-1-i])
			{
				num++;
			}
		}
	}

    
    cout <<num;
	return 0;
}
