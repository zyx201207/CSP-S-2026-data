#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500200],hl,sdw[500200],wds[500500],da[500500];
string s1,s2;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(sdw[a[j]])
			{
				for(int k=sdw[a[j]]+1;k<=hl;k++)
				{
					sdw[wds[k]]=0;
					wds[k]=0;
				}
				hl=sdw[a[j]];
			}
			else 
			{
				hl++;
				wds[hl]=a[j];
				sdw[a[j]]=hl;
			}
		}
		for(int j=1;j<=hl;j++)
		{
			da[wds[j]]++;
			sdw[wds[j]]=0;
			wds[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<da[i]<<" ";
} 
