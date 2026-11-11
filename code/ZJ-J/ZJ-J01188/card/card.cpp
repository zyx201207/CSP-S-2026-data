#include<bits/stdc++.h>
using namespace std;
int cnt[10000005],f[10000005];
struct p
{
	int s;
	int flag=1;
};
p a[10000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i].s;
	for(int o=1;o<=n;o++)
	{	
		for(int i=1;i<=n;i++)
			a[i].flag=1;
		for(int i=1;i<=m;i++)
			f[i]=1;
		for(int i=o;i<n;i++)
			for(int j=o;j<i;j++)
				if(a[j].flag==1&&a[j].s==a[i].s)
					for(int k=j;k<i;k++)
						a[k].flag=0; 
		for(int i=o;i<=n;i++)
			if(a[i].flag==1&&f[a[i].s]==1)
			{
				cout<<endl<<o<<endl;
				cnt[a[i].s]++;
				f[a[i].s]=0;
			}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
