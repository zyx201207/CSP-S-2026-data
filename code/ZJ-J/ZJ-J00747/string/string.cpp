#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n,a[N],ans,sum,p;
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++)	cin >> a[i] >> b[i],sum+=a[i];
	if (sum <= 1e8)
	{
		string s=" ";
		for (ll i = 1; i <= n; i++) for (ll j = 1; j <= a[i]; j++) s+=b[i];
		for (ll i = 1; i <= (sum+1)/2; i++)
		{
			ll j=sum-i+1;
			if (s[i] != s[j]) ans++;
		}
		cout << ans;
		return 0;
	}
	ll i=1,j=n;
	while (1)
	{
		if (i >= j) break;
		while (b[i] == b[j])
		{
			if (i >= j)
			{
				cout << ans;
				return 0;
			}
			if (a[i] > a[j]) a[i]-=a[j],j--;
			else if (a[i] < a[j]) a[j]-=a[i],i++;
			else i++,j--;
		}
		if (a[i] > a[j])
		{
			a[i]-=a[j];
			ans+=a[j];
			j--;
		}
		else if (a[i] < a[j])
		{ 
			a[j]-=a[i];
			ans+=a[i];
			i++;
		}
		else
		{
			ans+=a[i];
			i--,j++;
		}
	}
	cout << ans;
	return 0;
}
// I am sb
// luogu: @people123
