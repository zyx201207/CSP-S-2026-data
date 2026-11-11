#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],as;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=1,s=0;
	while(l<n)
	{
		while(r<n&&s+(r-l+1)*(a[r+1]-a[r])<=m)
		{
			s+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		as=max(as,r-l+1);
		if(l==r)
		{
			l++,r++;
			s=0;
		}
		else
		{
			s-=a[r]-a[l];
			l++;
		}
	}
	cout<<as;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/