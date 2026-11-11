#include<bits/stdc++.h>
using namespace std;
int n,m,a[700010],lst[700010],b[700010],cnt[700010],tot;
int main()
{
	//freopen("card5.in","r",stdin);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	int f=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i-1]>a[i])
		{
			f=0;
		}
		lst[a[i]]=i;
	}
	if(f==1)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<lst[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			lst[j]=0;
		}
		for(int j=0;j<=tot;j++)
		{
			b[j]=0;
		}
		tot=0;
		for(int j=i;j<=n;j++)
		{
			if(!lst[a[j]])
			{
				lst[a[j]]=tot+1;
				b[++tot]=a[j];
			}
			else
			{
				for(int k=lst[a[j]]+1;k<=tot;k++)
				{
					lst[b[k]]=0;
				}
			//	cout<<"---|  "<<a[j]<<" "<<lst[a[j]]<<endl;
				tot=lst[a[j]];
			}
		}
		for(int j=1;j<=tot;j++)
		{
			cnt[b[j]]++;
		}
	}
	for(int j=1;j<=m;j++)
	{
		cout<<cnt[j]<<" ";
	}
	return 0;
}
