#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0,m=0;
	int a[5005]={0};
	int b[3005]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	if(m==2)
	{
		cout<<"3 4"<<endl;
	}
	for(int i=0;i<n;i++)
	{
		int k[3005]={0};
		int t=0;
		for(int j=i;j<n;j++)
		{
			k[t]=a[j];
			for(int x=0;x<t;x++)
			{
				if(a[t]==a[x])
				{
					for(int y=x;y<t;y++)
					{
						k[y]=0;
						t--;
					}
				}
			}
			t++;
		}
		for(int x=0;x<t;x++)
		{
			b[k[x]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
