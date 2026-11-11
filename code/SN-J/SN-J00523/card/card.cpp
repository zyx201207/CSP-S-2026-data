#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005],q;
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
		int d[500005],k=i,q=1;//k shou pai qi shi
		for(int j=k;j<=n;j++)//kai shi da
		{
			bool p=true;
			for(int l=1;l<=n;l++)//jian cha zhuo zi
			{
				if(d[l]==a[j])
				{
					for(int h=l;h<=n;h++)
					{
						d[h]=0;
					}
					d[l]=a[j];
					q=l+1;
					p=false;
					break;
				}
			}
			if(p==true)
			{
				d[q]=a[j];
				q++;
			}
		}
		for(int c=1;c<=n;c++)
		{
			t[d[c]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
