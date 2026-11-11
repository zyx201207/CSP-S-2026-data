#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],rc[500005],ls[500005];
int n;
int main()
{
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=2;i<=n;i++)
	{
		rc[i]=(a[i]-a[i-1])*(i-1)+rc[i-1];
	}
	int lenr=n,lenl=upper_bound(rc+1,rc+n+1,m)-rc;
	if(rc[lenl]!=m)	lenl-=1;
	int maxx=lenl;
	for(int i=n-1;i<=1;i++)
	{
		if(a[i+1]-a[i]>m)
		{
			lenr--;
		}
	}
	for(int i=lenr;i>=lenl;i--)
	{
		for(int j=1;j<=i;j++)
		{
			if(rc[i]-rc[j]<=m)
			{
				maxx=max(maxx,j-i);
			}
		}
	}
	cout<<maxx;
	return 0;
}
