#include<bits/stdc++.h>
using namespace std;

long long n,m,s[500005],p,c,q,ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++)
	{
		s[i]=a[i]-a[i-1]; 
	}
	for(int i=1;i<n;i++)
	{
		c=1;
		if(s[i]>m)
		{
			if(ans<c) ans=c;
			continue;
		}
		else
		{
			c++;
			p=s[i];
		}
		for(int j=1;j<n;j++)
		{
			if(i+j==n) break;
			q=j;
			if(p+s[i+j]*(j+1)<=m)
			{
				p+=s[i+j]*(j+1);
				c++;
			}
			else break;	
		}
		if(c>ans) ans=c;
		if((i+q)==n-1) break;
	}
	cout<<ans<<endl;
	return 0;
 } 
