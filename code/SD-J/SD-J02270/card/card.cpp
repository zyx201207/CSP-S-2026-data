#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int s[N];
int d[N];
int c[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		s[i]=a;
	}
	for(int z=1;z<=n;z++)
	{
		for(int b=z;b<=n;b++)
		if(s[b]!=s[b+1])
		{
			break;
		}
		for(int i=z;i<=n;i++)
	    {
		    for(int q=1;q<=i;q++)
		    {
		        if(s[i]==s[q])
			    {
				    for(int e=q;e<i;e++)
				    {
					    c[e]=1;
				    }
			    }
		    }
	    }
	    for(int g=z;g<=n;g++)
	    {
		    if(c[g]!=1)
		    {
			    d[s[g]]++;
		    }
	    }
	    for(int y=1;y<=n;y++)
	    {
	    	c[y]=0;
		}
	}
	for(int x=1;x<=m;x++)
	{
		cout<<d[x]<<" ";
	}
	return 0;
}
