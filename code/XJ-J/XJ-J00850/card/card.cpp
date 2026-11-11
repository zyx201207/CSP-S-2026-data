#include<bits/stdc++.h>
using namespace std;
int m,n,cnt=0;
int pd[500005]={0},app[500005]={0},flag[500005]={0},num[300005]={0},num_place[300005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>pd[i];
	}
	int j,q=0;
	for(int i=1;i<=n;i++)
	{
		j=0;
		j=j+q;
		for(int k=j+1;k<=n;k++)
		{
			if(num[pd[k]]==0)
			{
				flag[cnt]=pd[k];
				num[pd[k]]=1;
				num_place[pd[k]]=cnt;
			}
			else if(num[pd[k]]==1)
			{
				int t;
				t=cnt;
				cnt=num_place[pd[k]];
				for(int p=cnt+1;p<=t;p++)
				{
					num_place[flag[cnt]]=0;
					num[pd[k]]=0;
					flag[p]=0;
				}
			}
			j++;
			flag[0]=0;
			for(int p=1;p<=cnt;p++)
			{
				app[flag[p]]++;
				flag[p]=0;
				num[flag[p]]=0;
			}
		}
		q++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<app[i]<<" ";
	}
	return 0;
}