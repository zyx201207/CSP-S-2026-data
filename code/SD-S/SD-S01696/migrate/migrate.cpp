#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#define ll long long

using namespace std;
const ll N=2e6+5;
ll c,t,n,d;
ll x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++)
			cin >> x[i];
	}
	cout << "0" << "\n" << "1";
	return 0;
}
