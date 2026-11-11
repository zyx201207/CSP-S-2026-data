#include<bits/stdc++.h>
using namespace std;
int a[500010],num[500010],sumsum[500010],t,ans;
int main()
{
	freopen("crystal .in","r",stdin);
	freopen("crystal .out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		num[i]=a[i]-a[i-1];
		sumsum[i]=sumsum[i-1]+(i-1)*num[i];
		if(sumsum[i]>m)
		{
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}		
