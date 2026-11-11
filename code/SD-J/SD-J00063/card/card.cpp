#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005];
int b[300005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			b[j]=0;
			c[j]=0; 
		}
		b[a[i]]=1;
		c[0]=a[i];
		long long l=0;
		for(int j=i+1;j<n;j++)
		{
			if(b[a[j]]!=0)
			{
				for(int p=b[a[j]];p<=l;p++)
				{
					b[c[p]]=0;
					c[p]=0;
				}
				l=b[a[j]];
			}
			else
			{
				l++;
				b[a[j]]=l;
				c[l]=a[j];
			}
		}
		for(int j=0;j<=n;j++)
		{
			ans[c[j]]++;
		} 
	}
	for(int i=1;i<m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<ans[m];
	cout<<"\n";
	return 0;
}
