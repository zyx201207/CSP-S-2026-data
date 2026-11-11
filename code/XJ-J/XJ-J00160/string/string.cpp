#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[200005];
	char c[200005];
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	string j=s;
	string q,h;
	long long sum=s.size();
	long long ans=s.size()/2;
	long long l=0;
	reverse(s.begin(),s.end());
	if(j==s)
	{
		cout<<0;
	}
	else
	{
	    for(long long i=1;i<=sum;i++)
	    {
	    	if(i<ans)
	    	{
	    		q+=s[i];
			}
			if(i>ans)
			{
				h+=s[i];
			}
		}
		for(long long i=1;i<=ans;i++)
		{
			if(q[i]!=s[i])
			{
				l++;
			}
		}
		cout<<l;
	}
	return 0;
}
