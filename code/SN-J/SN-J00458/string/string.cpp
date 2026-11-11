#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+10;
ll n;
ll a[maxn];
string c[maxn];
ll ans = 0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i] >> c[i];
	}
	for(int i=1,j=n; i<=n && j>=1; i++,j--)
	{
		if(i >= j) break;
		if(c[i] == c[j]) continue;
		if(a[i] > a[j])
		{
			ans += a[j];
			a[i] -= a[j];
			i--;
		}
		else if(a[j] > a[i])
		{
			ans += a[i];
			a[j] -= a[i];
			j++;
		}
		else
		{
			ans += a[i];
			a[i] = 0;
			a[j] = 0;
		}
	}
	cout << ans;
	return 0;
}
