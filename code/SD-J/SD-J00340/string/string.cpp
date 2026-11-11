#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 10;
const ll MOD = 998244353;
const ll inf = 9e18;
ll a[N];
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n;
	cin>>n;
	for(ll i = 1;i <= n;i++)
	{
		cin>>a[i]>>c[i];
	}
	ll cnt = 0;
	for(ll i = 1,j = n;i < j;)
	{
		if(a[i] > a[j])
		{
			a[i] -= a[j];
			if(c[i] != c[j]) cnt += a[j];
			a[j] = 0;
		}
		else
		{
			a[j] -= a[i];
			if(c[i] != c[j]) cnt += a[i];
			a[i] = 0;
		}
		if(a[i] == 0) i++;
		if(a[j] == 0) j--;
	}
	
	cout<<cnt;
	return 0;
}
