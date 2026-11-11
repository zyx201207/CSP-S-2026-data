#include<bits/stdc++.h>
using namespace std;
const int big=200005;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,q;
    cin>>n>>q;
    int a[big];
    int maxx=0;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	if(q==1)
	{
		for(int i=0;i<n;i++)
		{
			maxx=max(maxx,a[i]);
		}
	}
	else if(q==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int x;
				x=(a[i]&a[j]);
				maxx=max(maxx,x);
			}
		}
	}
	else if(q==3)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					int x;
					x=(a[i]&a[j]&a[k]);
					maxx=max(maxx,x);
				}
			}
		}
	}
	else if(q==4)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					for(int w=k+1;w<n;w++)
					{
						int x;
						x=(a[i]&a[j]&a[k]);
						maxx=max(maxx,x);
					}
				}
			}
		}
	}
	cout<<maxx;
    return 0;
}
//&
