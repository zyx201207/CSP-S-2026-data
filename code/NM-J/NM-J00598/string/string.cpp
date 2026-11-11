#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long sum=0,ans=0;
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
    	long long x;
    	char a;
    	cin>>x>>a;
    	sum+=x;
    	for(long long j=1;j<=x;j++)
    	{
    		s+=a;
		} 
	}
	long long z=sum/2;
	long long x=sum/2;
	if(sum%2==0)
	{
		for(long long i=z;i<=sum-1;i++)
		{
			if(s[i-x]!=s[i])
			{
				ans++;
			}
		}
	}else
	{
		z+=1;
		for(long long i=z;i<=sum-1;i++)
		{
			if(s[i]!=s[i-x-1])
			{
				ans++;
			}
		}
	}
	cout<<ans;
    return 0;
}
	
