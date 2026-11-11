#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
int n,m;
void slove()
{
	int ans=a[1];
	int pos=1;
	for(int i=2;i<=n;i++)
	{
		if(ans&a[i]==0)
		{
			continue;
		}
		else
		{
			ans&=a[i];
			pos++;
		}
		if(pos==m)
		{
			break;
		}
	}
	if(pos==m)
	{
		cout << ans << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int maxx=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		maxx=max(maxx,a[i]);	
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans << endl;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout << ans << endl;
	}
	else
	{
		slove();
	}
	return 0;
}
