#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	vector<ll> a(n),prefix(n+1,0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	prefix[0] = a[0];
	for (int i = 1; i < n; ++i) {
		prefix[i] = prefix[i-1] + a[i];
	} 
	ll mid = 2;
	//cout << prefix[n-1] << '\n';
	while(mid < n) {
		ll cost = (mid-1) * a[mid] - prefix[mid-1];
		//cout << cost << '\n';
			if (cost <= m) {
			mid++;
		} else {
			break;
		}
	//	cout <<"mid = "<<mid<<" cost = "<< cost << '\n';
	}
	//ll cost = (315275 - 1) * a[315275] - prefix[315275-1];
	//cout << "debug mid 315275 = " << cost << '\n';
	cout << mid;
    return 0;
}
/*
5 5
1 2 4 8 9


*/

