#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005],b[500005]; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=m;i++)
    {
        s[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int  j1=1;
		for(int j=i;j<=n;j++)
		{
			b[j1]=a[j];
			j1++;
			for(int k=i;k<=j1;k++)
			{
				if(b[j]==a[k])
				{
					for(int i1=1;i1<=n;i1++)
					{
						b[i1]=0;
					}
					b[1]=a[k];
					j1=2;
					break;
				}
			}
		}
		for(int ia=1;ia<=j1;ia++)
		{
			for(int i1=1;i1<=m;i1++)
			{
				if(i1==ia)
				{
					s[i1]++;
				}
			}
		}
		for(int i1=1;i1<=n;i1++)
		{
			b[i1]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<' ';
	}
	return 0;
}
