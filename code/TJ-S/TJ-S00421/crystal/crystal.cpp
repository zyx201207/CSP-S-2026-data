#include <bits/stdc++.h>
#define ll long long
const int MAXN = 5e5+5;
using namespace std;

ll n,m;
ll a[MAXN];
ll minn = LONG_LONG_MAX;
ll cha[MAXN];
ll ans = 0;

bool is_a()
{
	for(int i=1; i<=n; i++)
	{
		if(a[i] != i) return false;
	}
	return true;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}

	if(is_a())
	{
		sort(a+1,a+n+1);
		for(int i=n; i>=1; i--)
		{
			int ch = a[n]-a[i];
			if(m >= ch)
			{
				m -= ch;
				ans++;
			}
			else
			{
				break;
			}
		}
		cout<<ans;
		exit(0);
	}
	
	
	
	
	for(int i=1; i<=n; i++)
	{
		int num=0;
		for(int j=1; j<=n; j++)
		{
			num += abs(a[i] - a[j]);
		}
		if(num <= minn)
		{
			minn = num;
			for(int j=1; j<=n; j++) cha[j] = abs(a[i]- a[j]);
		}
	}
	sort(cha + 1, cha+n+1);
//	cout<<minn<<endl;

	for(int i=1; i<=n; i++)
	{
		//cout<<cha[i]<<" ";
		if(m >= cha[i])
		{
			m -= cha[i];
			ans++;
		}
		else
		{
			break;
		}
		
	}

	if(m==0)
	{
		cout<<ans;
	}
	else
	{   
		cout<<m;
	}
	return 0;
}
