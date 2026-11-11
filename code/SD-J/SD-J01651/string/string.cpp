#include<bits/stdc++.h>
using namespace std;	
long long n,m[200005]={0},cnt=0,sum=0,ans=0;
long long bj=0,bj1=0;
string s;
char a[200005];
int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>m[i]>>a[i];
		if(m[1]!=m[i])
		{
			bj=1;
		}
		if(a[1]!=a[i])
		{
			bj1=1;
		}
		sum+=m[i];		
	}
	if(bj1==0)
	{
		cout<<0;
		return 0;
	}
	if(bj==0)
	{
		if(n%2==1)
		{
			for(long long i=1;i<=n;i++)
			{
				if(!(n/2+1==i))
				{
					s+=a[i];
				}		
			} 
		}
		else
		{
			for(long long i=1;i<=n;i++)
			{
				s+=a[i];		
			} 
		} 
	}
	else
	{
		if(sum%2==1)
		{
			for(long long i=1;i<=n;i++)
			{
				for(long long j=0;j<m[i];j++)
				{
					ans++;
					if(sum/2+1!=ans)
					{
						s+=a[i];
					}				
				}		
			}
		}
		else
		{
			for(long long i=1;i<=n;i++)
			{
				for(long long j=0;j<m[i];j++)
				{
					s+=a[i];				
				}		
			}
		}
	}	
	for(long long i=1;i<=s.size()/2;i++)
	{
		if(s[i-1]!=s[s.size()-i])
		{
			cnt++;
		} 
	}
	if(bj==0)
	{
		cout<<cnt*m[1];
		return 0;
	}
	cout<<cnt;
	return 0;
 } 
