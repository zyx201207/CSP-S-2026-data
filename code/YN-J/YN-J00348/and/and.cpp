#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200006],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if(m==1)
	{
		cout << a[n];
		return 0;
	}
	else if(m==n)
	{
		ans=a[n];
		for(int i=n-1;i>=1;i--)
		{
			ans=a[i]&ans;
		}
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((a[j] & a[i])>ans)
				{
					ans=a[j]&a[i];
				}
			}
	    }
    }
	cout << ans;
    return 0;
}
