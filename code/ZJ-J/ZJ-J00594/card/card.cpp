#include<bits/stdc++.h>
using namespace std;
int a[500010];
int c[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int b[500010];
		for(int j=i;j<=n;j++)
		{
			b[cnt]=a[j];
			for(int p=1;p<cnt;p++)
			{
				if(b[p]==b[cnt])
				{
					for(int q=p;q<cnt;q++)
					{
						b[q]=0;
					}
				}
			}
			cnt++;
		}
		for(int w=1;w<=cnt-1;w++)
		{
			c[b[w]]++;
		}
		cnt=1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
