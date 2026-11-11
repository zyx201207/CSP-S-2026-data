#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long c[500010];
long long sc[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i]=a[i]-a[i-1];
	int temp=0;
	for(int i=1;i<=n;i++)
	{
		sc[i]+=c[i]*(i-1);
		if(sc[i]>m)
		{
			temp=i;
			break;
		}
	}
	cout<<temp-1;
	return 0;
} 
