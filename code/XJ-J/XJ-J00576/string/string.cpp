#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,sum;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long s=n+5;
	long long c[s];
	char t[n];
	for(int i=0;i<n;i++)
	{
		cin>>c[i]>>t[i];
		sum+=c[i];
	}
	sort(c,c+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(t[i]==t[0])
		{
			cnt++;
		}
	}
	if(cnt==n)
	{
		cout<<0;
	}
	else
	{
		if(c[0]*2-2>sum||c[0]*2-1==sum)
	    {
		    cout<<sum-c[0];
	    }
	    else if(c[0]*2==sum)
	    {
		    cout<<c[0];
	    }
	    else 
	    {
		    return 0;
	    }
	}
	return 0;
}