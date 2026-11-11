#include<bits/stdc++.h>
using namespace std;
long long x,a[500005],m,sum;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2==1)
		x=a[(n+1)/2];
	else
		x=a[x/2];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x)
			break;
		if(a[i]=x)
		{
			sum++;
			continue;
		}
		m=m-(x-a[i]);
		sum++;
	}
		cout<<sum;
	return 0;
}
