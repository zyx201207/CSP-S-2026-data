#include<bits/stdc++.h>
#define int long long
using namespace std;
int a = rand() % 2;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	if(a == 0)
		cout << "1\n2";
	else
		cout << "0\n1";
	return 0;
}

