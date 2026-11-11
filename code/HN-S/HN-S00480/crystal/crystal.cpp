#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
const ll N=5e5+5;
ll n, m;
ll a[N];
ll q[N];
ll ql=1, qr=0;
ll sum=0, maxx=0;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(ll i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(ll i=1; i<=n; i++)
	{
		sum+=(a[i]-a[i-1])*(qr-ql+1);
		q[++qr]=i;
		while(ql<=qr && sum>m)
		{
			sum-=a[i]-a[q[ql]];
			ql++;
		}
		maxx=max(maxx, qr-ql+1);
	}
	cout << maxx;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
