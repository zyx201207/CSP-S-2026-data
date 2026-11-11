#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

void fast_io(){
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
}

ll a;

map<ll,ll> mp;

int main(){
	fast_io();
	a = 100014;
	cout<<clock()<<"\n";
//	ll b;
	for(int i = 1 ; i <= 1e8 ; i++){
		a %= i;
		a %= (i << 2);
//		a %= (i << 24);
	}
	cout<<clock();

	return 0;
}

