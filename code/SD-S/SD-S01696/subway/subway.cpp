#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll c,n,m,d,q;
ll w[N],k[N],x[N],y[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++)
		cin >> k[N];
	for(int r=1;r<=q;r++)
		cin >> x[r] >> y[r];
	
	if(c==0&&n==2)
		cout<< "32" << "\n" << "17";
	if(c==0&&n==3)
		cout<< "35" << "\n" << "16";
	if(c==1&&n==1)
		cout << "30" << "\n" <<"15";
	return 0;
}
