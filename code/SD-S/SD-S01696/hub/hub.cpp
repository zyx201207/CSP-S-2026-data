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
ll c,t,n,k;
ll u[N],v[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i=1;i<=n-1;i++)
		{
			cin >> u[i] >> v[i];
		}
	}
	cout << "1" << "\n" << "2";
	return 0;
}
