#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int q[500010];
int cnt[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)cout<<n;
	else if(m==2)
	{
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++)
		{
			int temp=a[i];
			bool f=0;
			for(int j=i+1;j<=n;j++)
			{
				if(temp!=a[j])
				{
					if(f)
					{
						temp=a[j];
						f=0;
					}
					else
					{
						temp=a[j];
						f=1;
					}
				}
			}
			if(f==1)ans1++,ans2++;
			else
			{
				if(temp==1)ans1++;
				else ans2++;
			}
		}
		cout<<ans1<<" "<<ans2;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int num=0;
			for(int j=i;j<=n;j++)
			{
				int temp=num;
				bool f=0;
				for(int k=1;k<=temp;k++)
				{
					if(!f)
					{
						if(q[k]==a[j])
						{
							f=1;
							num=k;
						}
					}
					else q[k]=0;
				}
				if(!f)q[++num]=a[j];
			}
			for(int j=1;j<=num;j++)
			{
				cnt[q[j]]++;
				q[j]=0;
			}
		}
		for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	}
	return 0;
}
