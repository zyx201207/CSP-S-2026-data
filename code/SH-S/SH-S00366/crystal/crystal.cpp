#include<bits/stdc++.h>
using namespace std;
long long a[500006],n,m,d=0,s=0,maxx=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(s+(a[i]-a[i-1])*d<=m) s+=(a[i]-a[i-1])*d,d++;
		else
		{
			while(s+(a[i]-a[i-1])*d>m) d--,s-=a[i-1]-a[i-d-1];
			d++,s+=(a[i]-a[i-1])*d;
		}
		maxx=max(maxx,d);
	}
	cout<<maxx;
	return 0;
}
