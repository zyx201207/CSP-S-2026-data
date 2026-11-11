#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int e=1;e<=n;e++)
	{
		int b[300005];
		memset(b,0,sizeof b);
		for(int i=e;i<=n;i++)
		{
			b[a[i]]++;
			if(b[a[i]]>1)
			{
				for(int j=i-1;j>=e;j--)
				{
					b[a[j]]--;
					if(a[j]==a[i]) break;
				}	
			}
		}
		for(int i=1;i<=m;i++)
			if(b[i]>0)t[i]+=b[i];
	}	
	for(int i=1;i<=m;i++)
		cout<<t[i]<<" ";
	return 0;	
}
