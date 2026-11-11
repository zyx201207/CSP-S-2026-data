#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500011];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int pl=a[1]+1;
	for(int i=1;i<=n;i++)
	{
		a[i]+=pl;
	}
	int l=1,r=1;
	int maxn=1;
	int now=a[1];
	while(l<n)
	{
		int red=(r-l+1)*a[r];
		if((red-now)<=m)
		{
			maxn=max(maxn,r-l+1);
			r++;
			if(r==n+1) break;
			now+=a[r];
		}
		else
		{
			now-=a[l];
			l++;
		}
		if(n-l+1<=maxn) break;
	}
	cout<<maxn<<endl;
	return 0;
}