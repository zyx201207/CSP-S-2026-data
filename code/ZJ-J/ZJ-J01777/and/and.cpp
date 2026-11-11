#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	m--;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[n];
	if(m==0)cout<<a[n];
	else
	{
		for(int i=n-1;i>=1;i--)
		{
			ans&=a[i];
			m--;
			if(m==0)
			{
				cout<<ans;
				break;
			}
		}
	}
	return 0;
}