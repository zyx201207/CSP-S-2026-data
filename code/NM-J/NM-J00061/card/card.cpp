#include <bits/stdc++.h>
using namespace std;
#define ll long long


int n,m,l,a[200050],t[200050],h[300050],ans[300050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		l=0;
		for(int j=1;j<=m;j++)
		{
			h[j]= -1;
		}
		for(int j=i;j<=n;j++)
		{
			if(h[a[j]]== -1)
			{
				l++;
				t[l]=a[j];
				h[a[j]]=l;
			}else{
				for(int k=h[a[j]]+1;k<=l;k++)
				{
					h[t[k]]=-1;
				}
				l=h[a[j]];
			}
		}
		for(int i=1;i<=l;i++)
		{
			ans[t[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
}
 
