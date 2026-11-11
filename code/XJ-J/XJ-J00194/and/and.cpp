#include<bits/stdc++.h>
using namespace std; 

typedef long long ll;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m; 
	cin >> n >> m;
	vector<ll> a(n);
	ll maxx = -1;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		maxx = max(a[i],maxx);
	}
	sort(a.begin(),a.end());
	cout << a[n-m];	
	return 0;
}
