#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],maxx,fr[500010],j=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)fr[i]=fr[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		long long t=a[i]*(i-j+1)-(fr[i]-fr[j-1]);
		while(t>m)
		{
			j++;
			t=a[i]*(i-j+1)-(fr[i]-fr[j-1]);
		}
		maxx=max((i-j+1),maxx);
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
