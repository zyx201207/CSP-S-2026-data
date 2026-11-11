#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],num[300005],l[300005];
struct LAST
{
	int val,id;
}la[300005];
bool cmp(LAST a,LAST b)
{
	return a.id<b.id;
}
int find(int x)
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(la[mid].id==x)
		{
			return mid;
		}
	}
	return 0;
}
signed main()
{
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		la[a[i]].id=i,la[a[i]].val=a[i];
		l[a[i]]=i;
	}
	sort(la+1,la+n+1,cmp);
	for(int i=n;i>=1;i--)
	{
		if(l[a[i]]>i)
		{
			num[a[i]]++;
			for(int j=find(l[a[i]]);j<=m;j++)
			{
				num[la[j].val]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
