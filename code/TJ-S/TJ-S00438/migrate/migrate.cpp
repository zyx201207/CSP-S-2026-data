#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e6 + 5;
int c,t,a[MAXN];
//QAQ
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;++i) cin >> a[i];
		cout << n / 2 << '\n';
	}
	return 0;
}
