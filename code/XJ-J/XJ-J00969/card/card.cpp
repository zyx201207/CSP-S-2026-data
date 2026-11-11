#include<bits/stdc++.h>
using namespace std;
int n,m;	
int a[500005],b[300005];
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
		int dong[n+5],pos=1,pos1=1;
		for(int j=i;j<=n;j++)
		{
			dong[pos]=a[j];
			pos++;
			pos1++;
			for(int k=1;k<pos;k++)
			{
				if(a[j]==dong[k])
				{
					for(int l=k;l<pos-1;l++)
					{
						dong[l]=dong[l+j-k];
						pos1--;
					}
				}
			}
			pos=pos1;
		}
		for(int j=1;j<=n;j++)
		{
			b[dong[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}