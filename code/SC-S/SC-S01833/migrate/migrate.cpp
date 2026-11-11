#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int c;
ll t;
int n,d;
vector <int> x;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> c >> t;
	while (t --){
		cin >> n >> d;
		x.resize(n+1);
		for (int i = 1;i <= n;i ++)
			cin >> x[i];
	}
	
	return 0;
}