#include<bits/stdc++.h>
using namespace std;
int cnt[300005];
int xy[300005];
struct node
{
	int sz;
	int bj;
}a[500005];
long long n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].sz;
		if(xy[a[i].sz])
		{
			int zz=xy[a[i].sz];
			while(a[zz].bj) zz=a[zz].bj;
			a[zz].bj=i;
		}
		else xy[a[i].sz]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1+i-1;j<=n;j++)
		{
			while(a[j].bj) j=a[j].bj;
			cnt[a[j].sz]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
