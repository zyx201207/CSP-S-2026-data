//孙国轩 SN-J00764 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
long long a[200005],cnt[200005];
int main()
{
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}	
	for(int t=1;t<=n;t++)
	{
		long long b[100005]={};
		long long x=0;
		for(int i=t;i<=n;i++)
		{
			bool flag=true;
			for(int j=1;j<=x;j++)
			{
				if(a[i]==b[j])
				{
					for(int k=j+1;k<=x;k++)
					{
						b[k]=0;
					}
					x=j;
					b[j]=a[i];
					flag=false;
					break;
				}
			}
			if(flag)
			{
				b[++x]=a[i];
			}
		}
		for(int i=1;i<=x;i++)
		{
			cnt[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" "; 
	}
} 
