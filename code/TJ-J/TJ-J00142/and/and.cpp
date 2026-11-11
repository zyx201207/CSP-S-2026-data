#include <iostream>
using namespace std;
long long n,m,a[200005],ans,maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
    	cin >> a[i];
    	maxn=max(maxn,a[i]);
	}
	if (m==1) cout << maxn;
	else if (m==n)
	{
		ans=a[1];
		for (int i=1;i<=n;i++) ans=(ans&a[i]);
		cout << ans;
	}
	else if (m==n-1)
	{
		for (int i=1;i<=n;i++)
		{
			int x=a[1];
			for (int j=1;j<=n;j++)
			{
				if (j!=i) x=(x&a[i]);
			}
			if (x>ans) ans=x;
		}
		cout << ans;
	}
	else if (m==2)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if ((a[i]&a[j])>ans) ans=(a[i]&a[j]);
			}
		}
		cout << ans;
	}
	return  0;
}
