#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],q[N],cnt[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int hh=0,tt=0;
		for(int j=1;j<=n;j++) q[j]=0;
		for(int j=i;j<=n;j++)
		{
			q[++tt]=a[j];
			for(int k=0;k<=j-1;++k)
				if(q[k]==q[tt])
				{
					tt=k-1,q[++tt]=a[j];
					break;
				}
		}
		for(int j=hh;j<=tt;j++) cnt[q[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
