#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,k,dm;
bool flag;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	dm=m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	if(m==2)
	{
		sort(a+1,a+n+1);
		while(1)
		{
			ans=a[n];
			ans=ans&a[n-1];
			if(ans<=(a[n-1]&a[n-2])) n--;
			else 
			{
				cout << ans;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>=1;i--)
	{
		if(dm-1==0) break;
		ans=ans&a[i];
		dm--;
	}
	cout << ans;
	return 0;
}

