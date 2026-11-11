#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
int mp[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	int f=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i],mp[a[i]]++;
		if (a[i]>a[i-1])
			f=0;
	}
	if (f)
	{
		int s=mp[1];
		for (int i=1;i<=n;i++)
		{
			cout<<s<<' ';
			s+=mp[i+1];
		}
	}
	else
	{
		int ans1,ans2;
		ans1=ans2=0;
		for (int i=1;i<=n;i++)
		{
			int pos=i,pos2=i;
			for (int j=i;j<=n;j++)
			{
				if (a[j]==a[i])
					pos=j;
			}
			for (int j=pos+1;j<=n;j++)
			{
				if (a[j]==a[pos+1])
					pos2=j;
			}
			for (int j=pos2+1;j<=n;j++)
			{
				if (a[j]==1)
					ans1++;
				if (a[j]==2)
					ans2++;
			}
			if (pos!=i)
				ans1++;
			else if (pos2!=i)
				ans2++;
		}
		cout<<ans1<<' '<<ans2;
	}
	return 0;
}
//Trick||Treat!
