#include<bits/stdc++.h>
using namespace std;
int n,m,maxx,a[200005],ans,c,s,b,r;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	
	}
	for(int i=1;i<=m;i++)
	{
		b=0;
		for(int y=1;y<=n;y++)
		{
			if(i==1)
			{
				
				c=a[y];
			}
			else
			{
			    c=a[y]&r;
			}
			if(c>maxx)
			{
				maxx=c;
				b=y;
			}
		}
		a[b]=0;
		r=maxx;
		maxx=0;
	}
	cout<<r;
}
