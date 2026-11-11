#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;
int a[maxn];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int l=0,r=0,sumn=0,maxn=0;
	while(l<n&&l<=r)
	{
		while(sumn<=m&&r<n)
		{
			maxn=max(maxn,r-l+1);
			r++;
			sumn+=(a[l]-a[r]);
		}
		l++;
		sumn-=(a[l-1]-a[l])*(r-l+1);
	}
	cout<<maxn<<"\n";
	return 0;
}
