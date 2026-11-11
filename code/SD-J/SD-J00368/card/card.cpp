#include<bits/stdc++.h>
using namespace std;
long long n,m,s[500010],b[300010],c[300010],d[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(!b[s[i]]) b[s[i]]=i; 
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[s[j]]!=j)
			{
				j=b[s[j]]-1;
			}
			else
			{
				c[s[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
 }
