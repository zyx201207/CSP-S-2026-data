#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int M=3005;
int a[N],b[N],cnt[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,top,k;
	bool flag;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		top=0;
		for(j=i;j<=n;j++)
		{
			if(top==0)
			{
				flag=false;
			}
			else
			{
				for(k=1;k<=top;k++)
				{
					if(b[k]==a[j])
					{
						break;
					}
				}
				if(k>top)
				{
					flag=false;
				}
				else
				{
					flag=true;
				}
			}
			if(flag==false)
			{
				b[++top]=a[j];
			}
			else
			{
				top=k;
			}
		}
		for(j=1;j<=top;j++)
		{
			cnt[b[j]]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}