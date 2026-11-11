#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+5;

ll n, m, ans=1;
ll a[N];
bool flag=1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=i)
		{
			flag = 0;
		}
	}
	
	sort(a+1,a+1+n);
	
	if(!flag)
	{
		for(int i=n;i>1;i--)
		{
			ll num = 0, pos = 0;
			while(a[i]-a[i-pos]+num <= m && pos < i)
			{
				num += a[i]-a[i-pos];
				pos++;
			}
			ans = max(ans, pos);
		}
	}
	
	else
	{
		while(m-ans>=0)
		{
			m-=ans;
			ans++;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
